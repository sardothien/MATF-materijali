#define _XOPEN_SOURCE 700
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<sys/epoll.h>
#include<errno.h>
#include<string.h>
#include<limits.h>

#define check_error(expr, userMsg)\
    do{\
        if(!(expr)){\
            fprintf(stderr, "%s\n", userMsg);\
            exit(EXIT_FAILURE);\
        }\
    }while(0);
    
int main(int argc, char** argv){
    check_error(argc > 1, "arguments");
    
    int nFds = argc - 1;
    
    int epollFd = epoll_create(nFds);
    check_error(epollFd != -1, "epoll_create failed");
    
    int* fds = malloc(nFds * sizeof(int));
    check_error(fds != NULL, "malloc failed");
    
    int* fds_read = malloc(nFds * sizeof(int));
    check_error(fds_read != NULL, "malloc failed");
    
    struct epoll_event currEvent;
    
    for(int i = 0; i < nFds; i++){
        memset(&currEvent, 0, sizeof(struct epoll_event));
        
        currEvent.events = EPOLLIN | EPOLLERR | EPOLLHUP;
        currEvent.data.fd = open(argv[i+1], O_RDONLY | O_NONBLOCK);
        check_error(currEvent.data.fd != -1, "open failed");
        
        fds[i] = currEvent.data.fd;
        
        check_error(epoll_ctl(epollFd, EPOLL_CTL_ADD, currEvent.data.fd, &currEvent) != -1, "epoll_ctl failed");
    }
    
    struct epoll_event aFds[10];
    int min, minFd;
    int active = nFds;
    
    while(active){
        int retVal = epoll_wait(epollFd, aFds, 10, -1);
        check_error(retVal != -1, "epoll_wait failed");
        
        char buffer[100];
        
        for(int i = 0; i < retVal; i++){
            if(aFds[i].events & EPOLLIN){
                int readBytes = 0, total = 0;
                
                while((readBytes = read(aFds[i].data.fd, buffer, 100)) > 0)
                    total += readBytes;
                
                if(readBytes == -1)
                    if(errno != EAGAIN)
                        check_error(0, "read failed");
                    
                for(int j = 0; j < nFds; j++)
                    if(fds[j] == aFds[i].data.fd)
                        fds_read[j] += total;
    
            }
            else if(aFds[i].events & (EPOLLERR | EPOLLHUP)){
                close(aFds[i].data.fd);
                active--;
            }
        }
    }
    
    min = fds_read[0];
    minFd = 0;
    
    for(int i = 0; i < nFds; i++)
        if(fds_read[i] < min){
            min = fds_read[i];
            minFd = i;
        }
    
    char* name = strrchr(argv[minFd+1], '/');
    printf("%s\n", name != NULL ? name : argv[minFd+1]);
    
    free(fds);
    close(epollFd);
    
    exit(EXIT_SUCCESS);
}

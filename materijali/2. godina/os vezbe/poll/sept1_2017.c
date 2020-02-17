#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/epoll.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

typedef struct{
    FILE *in;
    float sum;
} data_t;
    
int main(int argc, char **argv){
    check_error(argc > 1, "arguments");
    
    int epollFd = epoll_create(argc);
    check_error(epollFd != -1, "epoll_create failed");
    
    int nFds = argc-1;
    
    data_t *d = calloc(nFds, sizeof(data_t));
    check_error(d != NULL, "calloc failed");
    
    struct epoll_event currentEvent;
    currentEvent.events = EPOLLIN;
    
    for (int i = 1; i < argc; ++i){
        int fd = open(argv[i], O_RDONLY | O_NONBLOCK);
        check_error(fd != -1, "open failed");
        
        d[i-1].in = fdopen(fd, "r");        
        check_error(d[i-1].in != NULL, "fdopen failed");
        
        currentEvent.data.ptr = &d[i-1];
        
        check_error(epoll_ctl(epollFd, EPOLL_CTL_ADD, fd, &currentEvent) != -1, "epoll_ctl failed");
    }
    
    int active = nFds;
    
    while (active){
        check_error(epoll_wait(epollFd, &currentEvent, 1, -1) != -1, "epoll_wait failed");
        
        data_t *current = currentEvent.data.ptr;
        
        if (currentEvent.events & EPOLLIN){
            float number;
            while (fscanf(current->in, "%f", &number) == 1) 
                current->sum += number;
        }
        else if (currentEvent.events & (EPOLLHUP | EPOLLERR)){
            fclose(current->in);
            active--;
        }
    }
    
    float max = INT_MIN;
    char *maxNaziv = NULL;
    for (int i = 0; i < nFds; ++i){
        if (d[i].sum > max){
            max = d[i].sum;
            maxNaziv = argv[i+1];
        }
    }
    
    printf("%s\n", maxNaziv);
    
    free(d);
    close(epollFd);
    
    return 0;
}

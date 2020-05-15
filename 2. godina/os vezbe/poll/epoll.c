#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/epoll.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
typedef struct {
  int fd;
  char* name;
}data_t;

int main(int argc, char** argv){
  check_error(argc > 1, "arguments");
    
  int epollFd = epoll_create(argc);
  check_error(epollFd != -1, "epoll_create failed");
  
  int nFds = argc-1;
  struct epoll_event* fds = malloc(nFds*sizeof(struct epoll_event));
  check_error(fds != NULL, "malloc failed");
  
  for(int i = 0; i < nFds; i++){
    int fd = open(argv[i+1], O_RDONLY | O_NONBLOCK);
    check_error(fd != -1, "open failed");
    
    data_t* d = malloc(sizeof(data_t));
    check_error(d != NULL, "malloc failed");
    
    d->fd = fd;
    d->name = argv[i+1];
    
    fds[i].events = EPOLLIN | EPOLLERR | EPOLLHUP;
    fds[i].data.ptr = d;
    
    check_error(epoll_ctl(epollFd, EPOLL_CTL_ADD, fd, fds[i].data.ptr) != -1, "epoll_ctl failed");
  }
  
  int active = nFds;
  struct epoll_event aFds[20];
  
  while(active){
    
    int retVal = epoll_wait(epollFd, aFds, 20, -1);
    check_error(retVal != -1, "epoll_wait failed");
    
    for(int i = 0; i < retVal; i++){
      if(aFds[i].events & EPOLLIN){
	data_t* d = aFds[i].data.ptr;
	char buffer[20];
	
	int readBytes;
	while((readBytes = read(d->fd, buffer, 20)) > 0)
	  check_error(write(STDOUT_FILENO, buffer, readBytes) != -1, "write failed");
	
	if(readBytes == -1)
	  if(errno != EAGAIN)
	    check_error(0, "read failed");
      }
      else if(aFds[i].events & (EPOLLERR | EPOLLHUP)){
	data_t* d = aFds[i].data.ptr;
	printf("Closing: %s\n", d->name);
	close(d->fd);
	free(d);
	active--;
      }
    }
  }
  
  exit(EXIT_SUCCESS);
}
#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <errno.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
// TERM1: mkfifo f1 f2 f3 f4
//	  ./poll f1 f2 f3 f4 
// TERM2: echo "asufgyha" > f1
//	  echo "asufgyha" > f2
//	  echo "asufgyha" > f3
//	  echo "asufgyha" > f4
int main(int argc, char** argv){
  check_error(argc > 1, "arguments");
  
  int nFds = argc-1;
  struct pollfd* fds = malloc(nFds*sizeof(struct pollfd));
  check_error(fds != NULL, "malloc failed");
  
  for(int i = 0; i < nFds; i++){
    int fd = open(argv[i+1], O_RDONLY | O_NONBLOCK);
    check_error(fd != -1, "open failed");
    
    fds[i].fd = fd;
    fds[i].events = POLLIN | POLLERR | POLLHUP;
    fds[i].revents = 0;
  }
  
  int active = nFds;
  while(active){
    int retVal = poll(fds, nFds, -1);
    check_error(retVal != -1, "poll failed");
    
    for(int i = 0; i < nFds; i++){
      if(fds[i].revents & POLLIN){
	char buffer[20];
	int readBytes = 0;
	
	while((readBytes = read(fds[i].fd, buffer, 20)) > 0)
	  check_error(write(STDOUT_FILENO, buffer, readBytes) != -1, "write failed");
	
	if(readBytes == -1)
	  if(errno != EAGAIN)
	    check_error(0, "read failed");
	  
	fds[i].revents = 0;
      }
      else if(fds[i].revents & (POLLERR | POLLHUP)){
	fds[i].fd = -1;
	fds[i].events = 0;
	fds[i].revents = 0;
	active--;
      }
    }
  }
  
  for(int i = 0; i < nFds; i++)
    if(fds[i].fd != -1)
      close(fds[i].fd);
    
  free(fds);
  
  exit(EXIT_SUCCESS);
}
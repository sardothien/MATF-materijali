#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <errno.h>
#include <string.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

int main(int argc, char** argv){
  check_error(argc > 1, "arguments");
  
  int nFds = argc - 1;
  
  struct pollfd* fds = malloc(nFds*sizeof(struct pollfd));
  check_error(fds != NULL, "malloc failed");
  
  int* brojac = calloc(nFds, sizeof(int));
  check_error(brojac != NULL, "calloc failed");
  
  for(int i = 0; i < nFds; i++){
    int fd = open(argv[i+1], O_RDONLY | O_NONBLOCK);
    check_error(fd != -1, "open failed");
    
    brojac[i] = 0;
    
    fds[i].fd = fd;
    fds[i].events = POLLIN | POLLERR | POLLHUP;
    fds[i].revents = 0;
  }
  
  int active = nFds;
  int maxBrPonavljanja = 0;
  char* max_name;
  
  while(active){
    int retVal = poll(fds, nFds, -1);
    check_error(retVal != -1, "poll failed");
    
    for(int i = 0; i < nFds; i++){
      if(fds[i].revents & POLLIN){
	int readBytes;
	char buffer[256];
	
	while((readBytes = read(fds[i].fd, buffer, 256)) > 0){
	  for(int j = 0; j < readBytes; j++)
	    if(buffer[j] == 'a')
	      brojac[i]++;
	}
	
	if(readBytes == -1)
	  if(errno != EAGAIN)
	    check_error(0, "read failed");
	  
	if(brojac[i] > maxBrPonavljanja){
	  maxBrPonavljanja = brojac[i];
	  max_name = argv[i+1];
	}
	
	fds[i].revents = 0;
      }
      else if(fds[i].revents & (POLLERR | POLLHUP)){
	close(fds[i].fd);
	fds[i].fd = -1;
	fds[i].events = 0;
	fds[i].revents = 0;
	active--;
      }
    }
  }
  
  char* name = strrchr(max_name, '/');
  printf("%s %d\n", name != NULL ? name : max_name, maxBrPonavljanja);
  
  for(int i = 0; i < nFds; i++)
    if(fds[i].fd != -1)
      close(fds[i].fd);
    
  free(fds);  
  
  exit(EXIT_SUCCESS);
}
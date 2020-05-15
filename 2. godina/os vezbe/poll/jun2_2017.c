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
  
  struct pollfd* fds = malloc(nFds * sizeof(struct pollfd));
  check_error(fds != NULL, "malloc failed");
  
  FILE** streams = malloc(nFds*sizeof(FILE*));
  check_error(streams != NULL, "malloc failed");
  
  for(int i = 0; i < nFds; i++){
    int fd = open(argv[i+1], O_RDONLY | O_NONBLOCK);
    check_error(fd != -1, "open failed");
    
    fds[i].fd = fd;
    fds[i].events = POLLIN | POLLERR | POLLHUP;
    fds[i].revents = 0;
    
    streams[i] = fdopen(fds[i].fd, "r");
    check_error(streams[i] != NULL, "fdopen failed");
  }
  
  int active = nFds;
  int maxBroj, broj;
  char* maxNaziv;
  int init = 0;
  
  while(active){
    int retVal = poll(fds, nFds, -1);
    check_error(retVal != -1, "poll failed");
    
    for(int i = 0; i < nFds; i++){
      if(fds[i].revents & POLLIN){
	
	while(fscanf(streams[i], "%d", &broj) == 1){
	  if(!init){
	    maxNaziv = argv[i+1];
	    maxBroj = broj;
	    init = 1;
	  }
	  else {
	    if(broj > maxBroj){
	      maxBroj = broj;
	      maxNaziv = argv[i+1];
	    }
	  }
	}
	
	fds[i].revents = 0;
      }
      else if(fds[i].revents & (POLLERR | POLLHUP)){
	fclose(streams[i]);
	close(fds[i].fd);
	fds[i].fd = -1;
	fds[i].events = 0;
	fds[i].revents = 0;
	active--;
      }
    }    
  }
  
  char* name = strrchr(maxNaziv, '/');
  printf("%d %s\n", maxBroj, name != NULL ? (name+1) : maxNaziv);
  
  for(int i = 0; i < nFds; i++)
    if(fds[i].fd != -1)
      close(fds[i].fd);
  
  free(fds);
  free(streams);
  
  exit(EXIT_SUCCESS);
}
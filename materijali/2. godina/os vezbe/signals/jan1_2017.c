#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  }while(0)
  
int sig1 = 0;
int sig2 = 0;
int shouldTerminate = 0;

void signalHandler(int signum){
  switch(signum){
    case SIGUSR1: ++sig1;
		  break;
    case SIGUSR2: ++sig2;
		  break;
    case SIGTERM: shouldTerminate = 1;
		  break;
    default: break;
  }
}
  
int main(){
  
  do {
    check_error(signal(SIGUSR1, signalHandler) != SIG_ERR, "sig1 failed");
    check_error(signal(SIGUSR2, signalHandler) != SIG_ERR, "sig2 failed");
    check_error(signal(SIGTERM, signalHandler) != SIG_ERR, "sigterm failed");
    
    pause();
  }while(!shouldTerminate);
  
  printf("%d %d\n", sig1, sig2);
  
  exit(EXIT_SUCCESS);
}
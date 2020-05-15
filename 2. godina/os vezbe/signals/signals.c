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
  
int signalCought = 0;
int shouldTerminate = 0;

void signalHandler(int signum){
  switch(signum){
    case SIGUSR1: signalCought = 1;
		  break;
    case SIGTERM: shouldTerminate = 1;
		  break;
    default: break;
  }
}
  
// TERM1: ./signals
// TERM2: ps -ax 
//	  kill -SIGUSR1 pid
int main(){
  
  printf("PID: %d\n", (int)getpid());
  
  check_error(signal(SIGUSR1, signalHandler) != SIG_ERR, "sig1 failed");
  check_error(signal(SIGTERM, signalHandler) != SIG_ERR, "sigterm failed");
  
  do{
    pause();
    
    if(signalCought){
      printf("Signal cought\n");
      signalCought = 0;
    }
  }while(!shouldTerminate);  
  
  exit(EXIT_SUCCESS);
}
#define _GNU_SOURCE
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
int sig1 = 0;
int sig2 = 0;
int shouldTerminate = 0;

void signalHandler(int signum){
  switch(signum){
    case SIGUSR1: sig1 = 1;
		  break;
    case SIGUSR2: sig2 = 1;
		  break;
    case SIGTERM: shouldTerminate = 1;
		  break;    
  }  
}

int main(){
  
  check_error(signal(SIGUSR1, signalHandler) != SIG_ERR, "signal failed");
  check_error(signal(SIGUSR2, signalHandler) != SIG_ERR, "signal failed");
  check_error(signal(SIGTERM, signalHandler) != SIG_ERR, "signal failed");
  
  do{   
    int n;
    scanf("%d", &n);
    
    pause();
    
    if(sig1){
      printf("%d\n", n > 0 ? n : -n);
      sig1 = 0;
    }
    else if(sig2){
      printf("%d\n", n*n);
      sig2 = 0;
    }
    
  }while(!shouldTerminate);
  
  
  exit(EXIT_SUCCESS);
}
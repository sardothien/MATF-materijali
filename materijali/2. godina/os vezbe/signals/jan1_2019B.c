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

int sig1 = 0, sig2 = 0;
int sigInt = 0;
int shouldTerminate = 0;
int skor = 0;

void signalHandler(int signum){
  switch(signum){
    case SIGUSR1: sig1 = 1; break;
    case SIGUSR2: sig2 = 1; break;
    case SIGINT: sigInt = 1; break;
    case SIGTERM: shouldTerminate = 1;
  }
}

int main(){

  check_error(signal(SIGUSR1, signalHandler) != SIG_ERR, "sig1 failed");
  check_error(signal(SIGUSR2, signalHandler) != SIG_ERR, "sig2 failed");
  check_error(signal(SIGINT, signalHandler) != SIG_ERR, "sigint failed");
  check_error(signal(SIGTERM, signalHandler) != SIG_ERR, "sigterm failed");
  
  do{
    pause();
    
    if(sig1){
      skor += 1;
      sig1 = 0;
    }
    else if(sig2){
      skor += 2;
      sig2 = 0;
    }
    else if(sigInt){
      skor -= 4;
      sigInt = 0;
    }
    
  }while(!shouldTerminate);
  
  printf("%d\n", skor);
  
  exit(EXIT_SUCCESS);
}
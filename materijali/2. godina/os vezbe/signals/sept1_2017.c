#define _GNU_SOURCE

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  }while(0)
  
int sig1 = 0, sig2 = 0;
int shouldTerminate = 0;  

void signalHandler(int signum){
  switch(signum){
    case SIGUSR1: sig1 = 1; break;
    case SIGUSR2: sig2 = 1; break;
    case SIGTERM: shouldTerminate = 1; break;
  }
}

int main(){
  
  check_error(signal(SIGUSR1, signalHandler) != SIG_ERR, "sig1 failed");
  check_error(signal(SIGUSR2, signalHandler) != SIG_ERR, "sig2 failed");
  check_error(signal(SIGTERM, signalHandler) != SIG_ERR, "sigterm failed");
  
  char rec[64];
  
  do{
    
    scanf("%s", rec);
    
    pause();
    
    if(sig1){
      int n = strlen(rec);
      while(n--)
	printf("%c", rec[n]);
      printf("\n");
      sig1 = 0;
    }
    else if(sig2){
      for(int i = 0; i < strlen(rec); i++)
	printf("%c", toupper(rec[i]));
      printf("\n");
      sig2 = 0;
    }
    
  }while(!shouldTerminate);
  
  exit(EXIT_SUCCESS);
}
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

#define check_error(expr, userMsg)\
    do{\
        if(!(expr)){\
            fprintf(stderr, "%s\n", userMsg);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
int sig1 = 0, sig2 = 0, sigint = 0;
int shouldTerminate = 0;

void signalHandler(int signum){
    switch(signum){
        case SIGUSR1: sig1 = 1; break;
        case SIGUSR2: sig2 = 1; break;
        case SIGINT: sigint = 1; break;
        case SIGTERM: shouldTerminate = 1; break;
    }
}

int main(){
    
    
    int x, y;
    
    do{
    check_error(signal(SIGUSR1, signalHandler) != SIG_ERR, "");
    check_error(signal(SIGUSR2, signalHandler) != SIG_ERR, "");
    check_error(signal(SIGINT, signalHandler) != SIG_ERR, "");
    check_error(signal(SIGTERM, signalHandler) != SIG_ERR, "");
        
        pause();
        
        scanf("%d%d", &x, &y);
        
        if(sig1){
            printf("%d\n", x^y);
            sig1 = 0;
        }
        else if(sig2){
            printf("%d\n", x&y);
            sig2 = 0;
        }
        else if(sigint){
            printf("%d\n", x|y);
            sigint = 0;
        }
                
    }while(!shouldTerminate);

    exit(EXIT_SUCCESS);
}

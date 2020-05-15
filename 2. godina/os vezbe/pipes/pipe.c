#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
#define RD_END (0)
#define WR_END (1)
#define MAX (256)

int main(){
  
  int par2cld[2];
  
  check_error(pipe(par2cld) != -1, "pipe failed");
  
  pid_t childPid = fork();
  check_error(childPid != -1, "fork failed");
  
  if(childPid > 0){
    close(par2cld[RD_END]);
    
    char buffer[MAX];
    sprintf(buffer, "Neka poruka\n");
    check_error(write(par2cld[WR_END], buffer, strlen(buffer)) != -1, "write failed");
    
    close(par2cld[WR_END]);
  }
  else {
    close(par2cld[WR_END]);
    
    char buffer[MAX];
    int readBytes = 0;
    
    readBytes = read(par2cld[RD_END], buffer, MAX);
    check_error(readBytes != -1, "read failed");
    
    check_error(write(STDOUT_FILENO, buffer, readBytes) != -1, "write failed");
    
    close(par2cld[RD_END]);
    exit(EXIT_SUCCESS);
  }
  
  check_error(wait(NULL) != -1, "wait failed");
  
  exit(EXIT_SUCCESS);
}
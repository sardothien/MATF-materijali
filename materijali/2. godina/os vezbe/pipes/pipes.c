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
  
  int par2cld[2], cld2par[2];
  
  check_error(pipe(par2cld) != -1, "pipe 1 failed");
  check_error(pipe(cld2par) != -1, "pipe 2 failed");
  
  pid_t childPid = fork();
  check_error(childPid != -1, "fork failed");
  
  if(childPid > 0){
    close(par2cld[RD_END]);
    close(cld2par[WR_END]);
    
    char* line = NULL;
    size_t lineLen = 0;
    
    check_error(getline(&line, &lineLen, stdin) != -1, "getline failed");
    check_error(lineLen < 256, "line too long");
    
    check_error(write(par2cld[WR_END], line, lineLen) != -1, "write failed");

    char buffer[MAX];
    int readBytes = 0;
    
    check_error((readBytes = read(cld2par[RD_END], buffer, MAX)) != -1, "read failed");
    check_error(write(STDOUT_FILENO, buffer, readBytes) != -1, "write failed");
    
    free(line);
    
    close(par2cld[WR_END]);
    close(cld2par[RD_END]);
  }
  else {
    close(par2cld[WR_END]);
    close(cld2par[RD_END]);
    
    char buffer[MAX];
    int readBytes = 0;
    memset(buffer, 0, MAX);
    
    strcpy(buffer, "Child: ");
    
    check_error(write(STDOUT_FILENO, buffer, strlen(buffer)) != -1, "write failed");
    
    readBytes = read(par2cld[RD_END], buffer, MAX);
    check_error(readBytes != -1, "read failed");
    
    check_error(write(STDOUT_FILENO, buffer, readBytes) != -1, "write failed");
    
    char* s = "SUCCESS\n";
    
    check_error(write(cld2par[WR_END], s, strlen(s)) != -1, "write failed");
    
    close(par2cld[RD_END]);
    close(cld2par[WR_END]);
    
    exit(EXIT_SUCCESS);
  }
  
  check_error(wait(NULL) != -1, "wait failed");  
  
  exit(EXIT_SUCCESS);
}
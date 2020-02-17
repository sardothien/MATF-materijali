#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

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

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  FILE *in = fopen(argv[1], "r");
  check_error(in != NULL, "fopen failed");
  
  char maxCommand[MAX];
  char maxArg[MAX];
  int maxNumOfBytes = 0;
  
  char* line = NULL;
  size_t lineLen;
  
  char command[MAX], argument[MAX];
  
  while(getline(&line, &lineLen, in) != -1){
    sscanf(line, "%s %s", command, argument);
    
    int cld2par[2];
    check_error(pipe(cld2par) != -1, "pipe failed");
    
    pid_t childPid = fork();
    check_error(childPid != -1, "fork failed");
    
    if(childPid == 0){
      close(cld2par[RD_END]);
      
      check_error(dup2(cld2par[WR_END], STDOUT_FILENO) != -1, "dup2 failed");
      
      check_error(execlp(command, command, argument, NULL) != -1, "execlp failed");
    }
    close(cld2par[WR_END]);
    
    int status;
    check_error(waitpid(childPid, &status, 0) != -1, "waitpid failed");
    
    int count = 0;
    char c[2];
    
    while(read(cld2par[RD_END], c, 1) == 1)
      count++;
    
    if(count > maxNumOfBytes){
      maxNumOfBytes = count;
      strcpy(maxArg, argument);
      strcpy(maxCommand, command);
    }
    
    close(cld2par[RD_END]);
  }
  
  printf("%s %s\n", maxCommand, maxArg);
  
  fclose(in);
  
  exit(EXIT_SUCCESS);
}
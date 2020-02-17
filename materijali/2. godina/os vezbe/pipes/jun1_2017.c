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

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  int cld2par[2];
  check_error(pipe(cld2par) != -1, "pipe failed");
  
  pid_t childPid = fork();
  check_error(childPid != -1, "fork failed");
  
  if(childPid > 0){
    close(cld2par[WR_END]);
    
    size_t lineLen = 0;
    char* line = NULL;
    
    FILE* in = fdopen(cld2par[RD_END], "r");
    check_error(in != NULL, "fdopen failed");
    
    while(getline(&line, &lineLen, in) != -1){
      char priv[11];
      sscanf(line, "%s", priv);
      printf("%s\n", priv);
    }
    
    free(line);
    fclose(in);
    close(cld2par[RD_END]);
  }
  else {
    close(cld2par[RD_END]);
    
    check_error(dup2(cld2par[WR_END], STDOUT_FILENO) != -1, "dup2 failed");
    
    check_error(execlp("ls", "ls", "-l", argv[1], NULL) != -1, "execlp failed");
    
    close(cld2par[WR_END]);
    
    exit(EXIT_FAILURE);
  }
  
  int status = 0;
  check_error(wait(&status) != -1, "wait failed");
  
  if(!WIFEXITED(status) || !(WEXITSTATUS(status) == EXIT_SUCCESS))
    printf("Neuspeh\n");
  
  exit(EXIT_SUCCESS);
}
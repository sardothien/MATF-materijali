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
  check_error(argc > 1, "arguments");
  
  int cld2par[2];
  check_error(pipe(cld2par) != -1, "pipe failed");
  
  pid_t childPid = fork();
  check_error(childPid != -1, "fork failed");
  
  if(childPid > 0){
    close(cld2par[WR_END]);
    
    FILE* in = fdopen(cld2par[RD_END], "r");
    check_error(in != NULL, "fdopen failed");
    
    char* line = NULL;
    size_t lineLen = 0;
    int linesRead = 0;
    
    while(getline(&line, &lineLen, in) != -1)
      linesRead++;
    
    int status = 0;
    check_error(wait(&status) != -1, "wait failed");
  
    if(WIFEXITED(status) && (WEXITSTATUS(status) == EXIT_SUCCESS)){
      printf("%d\n", linesRead);
    }
    else{
      printf("Neuspeh\n");
      exit(EXIT_FAILURE);
    }
        
    free(line);
    fclose(in);
    
    close(cld2par[RD_END]);
  }
  else{
    close(cld2par[RD_END]);
    
    char** array = NULL;
    array = malloc((argc+1) * sizeof(char*));
    check_error(array != NULL, "malloc failed");
    
    array[0] = strdup(argv[1]);
    check_error(array[0] != NULL, "strdup failed");
    
    int i = 0;
    for(i = 1; i < argc; i++){
      array[i] = strdup(argv[i]);
      check_error(array[i] != NULL, "strdup failed");
    }
    
    array[i] = NULL;
    
    check_error(dup2(cld2par[WR_END], STDOUT_FILENO) != -1, "dup2 failed");
    check_error(execvp(array[0], array+1) != -1, "execvp failed");
    
    close(cld2par[WR_END]);
  }
  
  exit(EXIT_SUCCESS);
}
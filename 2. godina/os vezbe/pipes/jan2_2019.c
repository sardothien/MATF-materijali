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
  
  int num = argc - 1;
  
  for(int i = 0; i < num; i++){
  
    int cld2par[2];
    check_error(pipe(cld2par) != -1, "pipe failed");
    
    pid_t childPid = fork();
    check_error(childPid != -1, "fork failed");
    
    if(childPid == 0) {
      close(cld2par[RD_END]);
      
      check_error(dup2(cld2par[WR_END], STDOUT_FILENO) != -1, "dup2 failed");      
      check_error(execlp("du", "du", "-sch", argv[i+1], NULL) != -1, "execlp failed");
    }
    
    close(cld2par[WR_END]);
    
    int status;
    check_error(wait(&status) != -1, "wait failed");
    
    if(WIFEXITED(status)){
      if(WEXITSTATUS(status) != EXIT_SUCCESS){
	printf("neuspeh ");
	continue;
      }
    }
    else if(WIFSIGNALED(status)){
      printf("neuspeh ");
      continue;
    }
    
    FILE *in = fdopen(cld2par[RD_END], "r");
    check_error(in != NULL, "fdopen failed");
      
    char* line = NULL;
    size_t lineLen = 0;
      
    getline(&line, &lineLen, in);
    size_t readChar = getline(&line, &lineLen, in);
    line[readChar] = '\0';
    
    char* size = malloc(readChar * sizeof(char));
    check_error(size != NULL, "malloc failed");
        
    sscanf(line, "%s", size);
    printf("%s ", size);
         
    free(line);
    fclose(in);    
  }
  
  printf("\n");
  
  exit(EXIT_SUCCESS);
}
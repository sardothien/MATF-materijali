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
#define MAX (1024)

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  int cld2par[2];
  
  check_error(pipe(cld2par) != -1, "pipe failed");
  
  pid_t childPid = fork();
  check_error(childPid != -1, "fork failed");
  
  if(childPid == 0){ // child
    close(cld2par[RD_END]);
    
    check_error(dup2(cld2par[WR_END], STDOUT_FILENO) != -1, "dup2 failed");
    
    check_error(execlp("stat", "stat", "--format=%s", argv[1], NULL) != -1, "execlp failed");    
  }
  
  close(cld2par[WR_END]);
  
  char buffer[MAX];
  
  check_error(read(cld2par[RD_END], buffer, MAX) != -1, "read failed");
  
  close(cld2par[RD_END]);
  
  int status = 0;
  check_error(waitpid(childPid, &status, 0) != -1, "waitpid failed");
  
  if(WIFEXITED(status)){
    if(WEXITSTATUS(status) != EXIT_SUCCESS){
      printf("Neuspeh\n");
      return 0;
    }
  }
  else{
    printf("Neuspeh\n");
    return 0;
  }
  
  int size;
  sscanf(buffer, "%d", &size);
  printf("%d\n", size);
  
  exit(EXIT_SUCCESS);
}

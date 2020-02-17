#define _XOPEN_SOURCE 700
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define check_error(expr, userMsg)\
    do { \
        if (!(expr)) { \
            fprintf(stderr, "%s\n", userMsg); \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

#define RD_END (0)
#define WR_END (1)
    
int main(int argc, char **argv){
  check_error(2 == argc, "args");

  int cld2par[2];
  check_error(pipe(cld2par) != -1, "pipe failed");
  
  pid_t childPid = fork();
  check_error(childPid != -1, "fork failed");
  
  if(childPid == 0) {
    close(cld2par[RD_END]);
    
    check_error(dup2(cld2par[WR_END], STDOUT_FILENO) != -1, "dup2 failed");
    check_error(execlp("ls", "ls", "-l", argv[1], NULL) != -1, "execlp failed");
    
    exit(EXIT_FAILURE);
  }
  
  close(cld2par[WR_END]);
  
  int status;
  check_error(wait(&status) != -1, "wait");
  if(!(WIFEXITED(status) && WEXITSTATUS(status)== EXIT_SUCCESS))
    check_error(0, "Greska");
    
  FILE *in = fdopen(cld2par[RD_END], "r");
  check_error(in != NULL, "fdopen failed");

  fscanf(in, "%*s %*s");
    
  char stampaj[1024];
    
  while(fscanf(in, "%*s %*s %*s %*s %*s %*s %*s %s %*s", stampaj) > 0)
    printf("%s\n", stampaj);
    
  fclose(in);
  
  exit(EXIT_SUCCESS);
}
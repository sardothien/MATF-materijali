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
  
#define MAX (256)
#define MAX_WRITE (4095)
#define RD_END (0)
#define WR_END (1)

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  FILE *in = fopen(argv[1], "r");
  check_error(in != NULL, "fopen failed");
  
  char command[MAX], argument[MAX];
  char *line = NULL;
  size_t lineLen;
  
  FILE* out = fopen("errors.txt", "w");
  check_error(out != NULL, "fopen failed");
  
  while(getline(&line, &lineLen, in) != -1){
    sscanf(line, "%s %s", command, argument);
    
    int cld2par[2];
    check_error(pipe(cld2par) != -1, "pipe failed");
    
    pid_t childPid = fork();
    check_error(childPid != -1, "fork failed");
    
    if(childPid == 0){
      close(cld2par[RD_END]);
      
      check_error(dup2(cld2par[WR_END], STDERR_FILENO) != -1, "dup2 failed");      
      check_error(execlp(command, command, argument, NULL) != -1, "execlp failed");
    }
    
    close(cld2par[WR_END]);
    
    int status;
    check_error(wait(&status) != -1, "status failed");
    
    char buffer[MAX_WRITE], error[MAX_WRITE];
    
    if(WIFEXITED(status)){
      if(WEXITSTATUS(status) != EXIT_SUCCESS){
	int readBytes;
	while(readBytes = read(cld2par[RD_END], buffer, MAX_WRITE)){
	  if(readBytes == -1)
	    break;
	  buffer[readBytes] = '\0';
	  strcat(error, buffer);
	}
	
	fprintf(out, "%s\n", error);
	error[0] = '\0';
      } 
    }
  }
  
  fclose(out);
  fclose(in);
  
  exit(EXIT_SUCCESS);
}
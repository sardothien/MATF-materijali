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

int main(int argc, char** argv){
  check_error(argc > 2, "arguments");
  
  char** args = malloc(sizeof(char*) * (argc+1));
  check_error(args != NULL, "malloc failed");
  
  args[0] = malloc(strlen(argv[1]) + 1);
  check_error(args[0] != NULL, "malloc failed");
  strcpy(args[0], argv[1]);
  
  int i = 0;
  for(i = 1; i < argc; i++){
    args[i] = malloc(strlen(argv[i]) + 1);
    check_error(args[i] != NULL, "malloc failed");
    strcpy(args[i], argv[i]);
  }
  
  args[i] = NULL;  
  
  pid_t childPid = fork();
  check_error(childPid != -1, "fork failed");
  
  if(childPid == 0){
    check_error(execvp(args[0], args+1) != -1, "execvp failed");
  }
  
  int status = 0;
  check_error(waitpid(childPid, &status, 0) != -1, "waitpid failed");
  
  if(!WIFEXITED(status) || (WIFEXITED(status) != EXIT_SUCCESS))
    printf("Neuspesno prevodjenje!\n");
  
  for(i = 0; i < argc; i++)
    free(args[i]);
  free(args);
  
  exit(EXIT_SUCCESS);
}
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
  check_error(argc == 2, "arguments");
  
  pid_t childPid = fork();
  check_error(childPid != -1, "fork failed");
  
  if(childPid == 0){
    check_error(execlp("gcc", "gcc", "-std=c99", argv[1], NULL) != -1, "execlp failed");
    
    exit(EXIT_FAILURE);
  }
  
  int status = 0;
  check_error(waitpid(childPid, &status, 0) != -1, "waitpid failed");
  
  if(WIFEXITED(status) && (WIFEXITED(status) == EXIT_SUCCESS)){
    struct stat fInfo;
    check_error(stat("a.out", &fInfo) != -1, "stat failed");
    printf("File size: %u\n", (unsigned)fInfo.st_size);
  }
  else {
    printf("Neuspesno prevodjenje!\n");
  }
  
  exit(EXIT_SUCCESS);
}
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define check_error(expr, userMsg)\
 do{\
  if(!(expr)){\
    fprintf(stderr, "%s\n", userMsg);\
    exit(EXIT_FAILURE);\
  }\
 }while(0)
 
int main(int argc, char** argv){
  check_error(argc > 1, "arguments");
  
  for(int i = 1; i < argc; i++){
    
    struct stat fInfo;
    check_error(stat(argv[i], &fInfo) != -1, "stat failed");
    check_error(S_ISDIR(fInfo.st_mode), "must be directory");
    
    if(!(fInfo.st_mode & S_IRWXO)){
      char* absPath = realpath(argv[i], NULL);
      check_error(absPath != NULL, "realpath failed");
      printf("%d\n", (int)strlen(absPath));
      free(absPath);
    }
  }

  exit(EXIT_SUCCESS);
}
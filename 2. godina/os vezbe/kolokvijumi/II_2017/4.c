#define _XOPEN_SOURCE 700

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // za realpath
#include <string.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
  }while(0)
  
void osMoveFile(const char *srcPath, const char *destPath){
  char* sPath = realpath(srcPath, NULL);
  char* dPath = realpath(destPath, NULL);
  
  check_error(sPath != NULL, "src file doesn't exist");
  
  if(sPath != NULL && dPath != NULL)
    check_error(strcmp(sPath, dPath) != 0, "same paths");
  
  free(sPath);
  free(dPath);
  
  check_error(rename(srcPath, destPath) != -1, "rename failed");
}

// ./4 srcPath destPath
int main(int argc, char** argv){
  check_error(argc == 3, "Arguments");
  
  osMoveFile(argv[1], argv[2]);
  
  exit(EXIT_SUCCESS);
}
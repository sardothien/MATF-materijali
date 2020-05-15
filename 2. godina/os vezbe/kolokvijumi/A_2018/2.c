#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 }while(0)
 
int main(int argc, char** argv){
  check_error(argc == 3, "Arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  check_error(S_ISDIR(fInfo.st_mode), "must be directory");
  
  char* newPath = malloc(strlen(argv[1]) + strlen(argv[2]) + 1);
  check_error(newPath != NULL, "malloc failed");
  
  strcpy(newPath, argv[1]);
  char* kosaCrta = strrchr(newPath, '/');
  if(kosaCrta == NULL)
    strcpy(newPath, argv[2]);
  else
    sprintf(kosaCrta + 1, "%s", argv[2]);
  
  check_error(rename(argv[1], newPath) != -1, "rename failed");
  
  free(newPath);
  
  exit(EXIT_SUCCESS);
}
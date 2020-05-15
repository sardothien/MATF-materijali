#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 } while(0)
 

int main(int argc, char** argv){
  check_error(argc == 3, "Arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  
  char* name = strrchr(argv[1], '/');
  double size = 0;
  char* s;
  
  if(!strcmp(argv[2], "KB")){
    size = (double)(fInfo.st_size * 1.0/1024);
    s = "KB";
  }
  else if(!strcmp(argv[2], "MB")){
    size = (double)(fInfo.st_size * 1.0/(1024*1024));
    s = "MB";
  }
  else if(!strcmp(argv[2], "GB")){
    size = (double)(fInfo.st_size * 1.0/(1024*1024*1024));
    s = "GB";
  }
  else{
    fprintf(stderr, "Wrong option\n");
    exit(EXIT_FAILURE);
  }
  
  size = ceil(size);
  printf("%s %d%s\n", name != NULL ? name + 1 : argv[1], 
		      (int)size, s);  
  
  exit(EXIT_SUCCESS);
}
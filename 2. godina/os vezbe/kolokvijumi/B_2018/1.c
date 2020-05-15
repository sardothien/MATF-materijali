#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define check_error(expr, userMsg)\
 do{\
  if(!(expr)){\
    fprintf(stderr, "%s\n", userMsg);\
    exit(EXIT_FAILURE);\
  }\
 }while(0)
 
int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  
  unsigned diff = (unsigned)(fabs(ceil((fInfo.st_atime - fInfo.st_mtime)/(60.0*60.0))));
  
  printf("%u\n", diff);
  
  exit(EXIT_SUCCESS);
}
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 } while(0)
 
#define SECS_PER_DAY (24*60*60)
 

int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  check_error(S_ISREG(fInfo.st_mode), "must be reg file");
  
  unsigned diff = (unsigned)((fInfo.st_atime - fInfo.st_mtime)/SECS_PER_DAY);
		  
  printf("%u\n", diff);
  
  exit(EXIT_SUCCESS);
}
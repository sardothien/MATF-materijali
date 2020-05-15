#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 } while(0)
 
int main(int argc, char** argv){
  check_error(argc == 4, "Arguments");
  
  long privileges = strtol(argv[3], NULL, 8);
  
  if(!strcmp(argv[1], "-f")){
    int fd = open(argv[2], O_RDONLY | O_CREAT, privileges);
    check_error(fd != -1, "open failed");
    close(fd);
  }
  else if(!strcmp(argv[1], "-d")){
    int retValue = mkdir(argv[2], privileges);
    if(retValue == -1)
      if(errno != EEXIST){
	fprintf(stderr, "mkdir failed");
	exit(EXIT_FAILURE);
      }	
  }
  else{
    //errno = EINVAL;
    fprintf(stderr, "Wrong option");
    exit(EXIT_FAILURE);
  }
  
  check_error(chmod(argv[2], privileges) != -1, "chmod failed");
    
  exit(EXIT_SUCCESS);
}
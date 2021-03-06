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
  mode_t oldUmask = umask(0);
  
  if(!strcmp(argv[1], "-f")){
    int fd = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, privileges);
    check_error(fd != -1, "open failed");
    close(fd);
  }
  else if(!strcmp(argv[1], "-d")){
    check_error(mkdir(argv[2], privileges) != -1, "mkdir failed");
  }
  else{
    fprintf(stderr, "Wrong option");
    exit(EXIT_FAILURE);
  }
    
  umask(oldUmask);  
  
  exit(EXIT_SUCCESS);
}

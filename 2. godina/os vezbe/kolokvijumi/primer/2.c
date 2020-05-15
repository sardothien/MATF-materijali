#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 }while(0)

void osMakeFile(const char* fName){  
  
  int fd = open(fName, O_WRONLY | O_CREAT | O_EXCL, 0733);
  if(fd == -1){
    if(errno == EEXIST)
      exit(EXIT_FAILURE);
    else
      exit(EXIT_FAILURE);
  }
  
  close(fd);
}

int main(int argc, char** argv){
  
  check_error(argc == 2, "Arguments");

  mode_t oldUmask = umask(0);
  osMakeFile(argv[1]);  
  umask(oldUmask);
  
  exit(EXIT_SUCCESS);
}

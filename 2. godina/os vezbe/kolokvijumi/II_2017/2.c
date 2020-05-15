#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
  }while(0)
  
void osMkPublicDir(const char *dname){
  mode_t oldUmask = umask(0);
  check_error(mkdir(dname, 0777) != -1, "mkdir failed");  
  umask(oldUmask);
}

// ./2 dirA
int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  osMkPublicDir(argv[1]);
  
  exit(EXIT_SUCCESS);
}
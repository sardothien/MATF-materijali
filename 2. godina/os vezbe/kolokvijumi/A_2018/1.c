#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <utime.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 }while(0)
 
int main(int argc, char** argv){
  check_error(argc == 3, "Arguments");
  
  time_t seconds = strtol(argv[2], NULL, 10);
  struct utimbuf vreme;
  vreme.actime = seconds;
  vreme.modtime = seconds;
  
  check_error(utime(argv[1], &vreme) != -1, "utime failed");
  
  exit(EXIT_SUCCESS);
}
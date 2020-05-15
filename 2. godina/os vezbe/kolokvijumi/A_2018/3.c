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
 }while(0)
 
int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  
  mode_t grp = fInfo.st_mode & S_IRWXG;
  mode_t oth = fInfo.st_mode & S_IRWXO;
  
  mode_t newMode = (fInfo.st_mode & S_IRWXU) | (grp >> 3) | (oth << 3);
  
  check_error(chmod(argv[1], newMode) != -1, "chmod failed");
  
  exit(EXIT_SUCCESS);
}
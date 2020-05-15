#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
  }while(0)
  
bool osIsPublicFile(const char* fPath){
  
  struct stat fInfo;
  check_error(stat(fPath, &fInfo) != -1, "stat failed");
  check_error(S_ISREG(fInfo.st_mode), "not regular file");
  
  if((fInfo.st_mode & S_IROTH) && (fInfo.st_mode & S_IWOTH))
    return true;
  else
    return false;
}

// ./1 test.txt
int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  bool result = osIsPublicFile(argv[1]);
  
  fprintf(stdout, "%s\n", (result == true) ?
			  "true" : "false");
  
  exit(EXIT_SUCCESS);
}
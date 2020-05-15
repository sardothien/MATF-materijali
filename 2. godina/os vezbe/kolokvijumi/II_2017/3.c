#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
  }while(0)
  
#define SECS_PER_DAY (24*60*60)
  
unsigned osNumOfDaysFileModified(const char *fPath){
  struct stat fInfo;
  check_error(stat(fPath, &fInfo) != -1, "stat failed");
  
  time_t now = time(NULL);
  check_error(now != -1, "time_t failed");
  
  unsigned days = (now - fInfo.st_mtime) / SECS_PER_DAY;
  return days;
}

// ./3 test.txt
// touch 1.txt --time=mtime --date="2004-02-27 14:19:13"
int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  unsigned days = osNumOfDaysFileModified(argv[1]);
  fprintf(stdout, "%u\n", days); 
  
  exit(EXIT_SUCCESS);
}
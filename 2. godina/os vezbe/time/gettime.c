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
  } while(0);
  
int main(){
  
  time_t now = time(NULL); // broj sekundi od epohe
  printf("%s", ctime(&now));
  
  struct tm* brokenTime = localtime(&now);
  check_error(brokenTime != NULL, "localtime failed");
  
  brokenTime->tm_year += 1;
  brokenTime->tm_mday -= 2;
  
  time_t newTime = mktime(brokenTime);
  printf("%s", ctime(&newTime));
  
  exit(EXIT_SUCCESS);
}
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  }while(0);
  
int main(){
  
  time_t now = time(NULL);
  
  struct tm* brokenTime = localtime(&now);
  check_error(brokenTime != NULL, "localtime failed");
  
  printf("%d\n", brokenTime->tm_yday + 1);
  
  exit(EXIT_SUCCESS);
}
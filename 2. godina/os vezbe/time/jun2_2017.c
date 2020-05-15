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
  
  char buffer[1024];
  strftime(buffer, 1024, "%W", brokenTime);
  printf("%s\n", buffer);
  
  exit(EXIT_SUCCESS);
}
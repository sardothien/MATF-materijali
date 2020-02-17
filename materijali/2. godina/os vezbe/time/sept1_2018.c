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
  
int main(int args, char** argv){
  check_error(args == 3, "args");
  
  time_t seconds = (time_t)atol(argv[1]);
  int brMinuta = atoi(argv[2]);
  
  seconds += brMinuta * 60;
  
  struct tm* brokenTime = localtime(&seconds);
  check_error(brokenTime != NULL, "localtime failed");
  
  char buffer[1024];
  strftime(buffer, 1024, "%d/%m/%Y %H:%M", brokenTime);
  printf("%s\n", buffer);

  exit(EXIT_SUCCESS);
}
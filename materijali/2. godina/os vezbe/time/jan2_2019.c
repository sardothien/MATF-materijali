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
  check_error(args == 2, "args");
  
  time_t seconds = (time_t)atol(argv[1]);
  
  struct tm* brokenTime = localtime(&seconds);
  check_error(brokenTime != NULL, "localtime failed");
  
  if(brokenTime->tm_hour >= 0 && brokenTime->tm_hour < 7)
    printf("noc\n");
  else if(brokenTime->tm_hour >= 7 && brokenTime->tm_hour < 9)
    printf("jutro\n");
  else if(brokenTime->tm_hour >= 9 && brokenTime->tm_hour < 12)
    printf("prepodne\n");
  else if(brokenTime->tm_hour >= 12 && brokenTime->tm_hour < 19)
    printf("popodne\n");
  else
    printf("vece\n");
  
  exit(EXIT_SUCCESS);
}
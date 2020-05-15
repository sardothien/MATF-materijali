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
  int brDana = atoi(argv[2]);
  
  struct tm* brokenTime = localtime(&seconds);
  check_error(brokenTime != NULL, "localtime failed");
  
  const char* months[] = {
    "januar", "februar", "mart", "april",
    "maj", "jun", "jul", "avgust", "septembar",
    "oktobar", "novembar", "decembar"
  };  
  
  printf("%s ", months[brokenTime->tm_mon]);
  
  seconds += brDana * (24*60*60);
  
  struct tm* brokenTime1 = localtime(&seconds);
  check_error(brokenTime1 != NULL, "localtime failed");
  
  printf("%s\n", months[brokenTime1->tm_mon]);
  
  exit(EXIT_SUCCESS);
}
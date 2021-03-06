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
  
  const char* days[] = {
    "nedelja", "ponedeljak", "utorak", "sreda",
    "cetvrtak", "petak", "subota"
  };
  
  printf("%s\n", days[brokenTime->tm_wday]); 
  
  exit(EXIT_SUCCESS);
}
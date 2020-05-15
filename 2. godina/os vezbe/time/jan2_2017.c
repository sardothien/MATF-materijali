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
  
  time_t now = time(NULL);
  
  int brDana = atoi(argv[1]);
  now += brDana * (24*60*60);
  
  struct tm* brokenTime = localtime(&now);
  check_error(brokenTime != NULL, "localtime failed");
  
  const char* days[] = {
    "nedelja", "ponedeljak", "utorak", "sreda", 
    "cetvrtak", "petak", "subota"
  };
  
  printf("%s %d\n", days[brokenTime->tm_wday], brokenTime->tm_mday);  
  
  exit(EXIT_SUCCESS);
}
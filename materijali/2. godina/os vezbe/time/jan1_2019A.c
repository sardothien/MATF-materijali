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
  int brGodina = atol(argv[2]);
  
  struct tm* brokenTime = localtime(&seconds);
  check_error(brokenTime != NULL, "localtime failed");
  
  int before = brokenTime->tm_wday;
  brokenTime->tm_year += brGodina;
  
  time_t after = mktime(brokenTime);
  check_error(after != -1, "mktime failed");
  
  brokenTime = localtime(&after);
  check_error(brokenTime != NULL, "localtime failed");
  
  int aft = brokenTime->tm_wday;
  
  const char* days[] = {
    "nedelja", "ponedeljak", "utorak", "sreda", 
    "cetvrtak", "petak", "subota"
  };
  
  printf("%s ", days[before]);    
  printf("%s\n", days[aft]); 
  
  exit(EXIT_SUCCESS);
}

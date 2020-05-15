#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  FILE* in = fopen(argv[1], "r+");
  check_error(in != NULL, "fopen failed");
  
  int fd = fileno(in);
  check_error(fd != -1, "fileno failed");
  
  char word[256];
  
  struct flock lock;
  while(fscanf(in, "%s", word) == 1){
    int number;
    if(sscanf(word, "%d", &number) == 1 && number > 999 && number < 10000){
      lock.l_type = F_WRLCK;
      lock.l_whence = SEEK_SET;
      lock.l_start = ftell(in);
      lock.l_len = -4;
      
      if(fcntl(fd, F_SETLK, &lock) != -1){
	check_error(fseek(in, -4, SEEK_CUR) != -1, "fseek failed");
	fprintf(in, "####");
      }
      else if(errno != EAGAIN){
	check_error(0, "fcntl failed");
      }	
    }
  }
  
  fclose(in);  
  
  exit(EXIT_SUCCESS);
}
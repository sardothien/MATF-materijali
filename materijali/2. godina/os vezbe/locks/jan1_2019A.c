#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

#define MAX (256)
  
int main(int argc, char** argv){
  check_error(argc == 3, "arguments");
  
  int fd = open(argv[1], O_RDONLY);
  check_error(fd != -1, "open failed");
  
  FILE *in = fdopen(fd, "r");
  check_error(in != NULL, "fdopen failed");
  
  int length = strlen(argv[2]);
  char buffer[MAX];
  
  while(!feof(in)){
    fscanf(in, "%s", buffer);
    if(!strcmp(buffer, argv[2])){
      struct flock lock;
      lock.l_type = F_WRLCK;
      lock.l_whence = SEEK_SET;
      lock.l_start = ftell(in);
      lock.l_len = -length;
      
      check_error(fcntl(fd, F_GETLK, &lock) != -1, "fcntl failed");
      
      long curr = ftell(in) - length;
      switch(lock.l_type){
	case F_WRLCK: printf("%ld w\n", curr);	
		      break;
	case F_RDLCK: printf("%ld r\n", curr);	
		      break;
	case F_UNLCK: break;
      }
    }
  }
  
  fclose(in);
  
  exit(EXIT_SUCCESS);
}
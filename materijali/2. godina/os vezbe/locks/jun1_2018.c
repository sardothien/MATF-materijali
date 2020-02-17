#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  int fd = open(argv[1], O_RDWR);
  check_error(fd != -1, "open failed");
  
  FILE *in = fdopen(fd, "r+");
  check_error(in != NULL, "fopen failed");
  
  int success = 0, failure = 0;
  char buffer[1024];
  
  while(fscanf(in, "%s", buffer) == 1){
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = ftell(in);
    lock.l_len = -strlen(buffer);
    
    if(fcntl(fd, F_SETLK, &lock) == -1){
      if(errno != EAGAIN && errno != EACCES)
	check_error(0, "fcntl failed");
      failure++;
      continue;
    }
    else{
      int n = strlen(buffer);
      char* s = malloc(n+1);
      check_error(s != NULL, "malloc failed");
      
      int k = 0;
      for(int i = n-1; i >= 0; i--)
	s[k++] = buffer[i];
      
      s[k] = 0;
      fseek(in, -n, SEEK_CUR);
      fprintf(in, "%s", s);
      free(s);
      lock.l_type = F_UNLCK;
      check_error(fcntl(fd, F_SETLK, &lock) != -1, "fcntl failed");
      success++;
    }
  }
  
  printf("%d %d\n", success, failure);
  
  fclose(in);
  
  exit(EXIT_SUCCESS);
}
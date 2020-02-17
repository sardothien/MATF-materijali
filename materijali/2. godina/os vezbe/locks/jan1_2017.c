#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

// ./1 path a b
int main(int argc, char** argv){
  check_error(argc == 4, "arguments");
  
  int fd = open(argv[1], O_RDWR);
  check_error(fd != -1, "open failed");
  
  int a = atoi(argv[2]);
  int b = atoi(argv[3]);
  
  struct flock lock;
  lock.l_type = F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = a;
  lock.l_len = b;
  
  check_error(fcntl(fd, F_GETLK, &lock) != -1, "fcntl failed");
  
  switch(lock.l_type){
    case F_UNLCK: printf("unlocked\n"); break;
    case F_RDLCK: printf("shared lock\n"); break;
    case F_WRLCK: printf("exclusive lock"); break;
  }
  
  lock.l_type = F_UNLCK;
  check_error(fcntl(fd, F_SETLK, &lock) != -1, "fcntl failed");
  
  close(fd);
  
  exit(EXIT_SUCCESS);
}
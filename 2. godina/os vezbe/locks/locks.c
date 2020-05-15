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
  
// ./1 path odakle koliko cekanje
int main(int argc, char** argv){
  check_error(argc == 5, "arguments");
  
  int fd = open(argv[1], O_RDWR);
  check_error(fd != -1, "open failed");
  
  int a = atoi(argv[2]);
  int n = atoi(argv[3]);
  int t = atoi(argv[4]);
  
  struct flock lock;
  lock.l_type = F_RDLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = a;
  lock.l_len = n;
  
  check_error(fcntl(fd, F_SETLK, &lock) != -1, "fcntl failed");
  
  sleep(t);
  
  lock.l_type = F_UNLCK;
  check_error(fcntl(fd, F_SETLK, &lock) != -1, "fcntl failed");
  
  close(fd);
  
  exit(EXIT_SUCCESS);
}
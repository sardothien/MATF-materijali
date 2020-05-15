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
 }while(0)
 
#define MAX_SIZE (256)
 
int main(int argc, char** argv){
  check_error(argc == 4, "arguments");
  
  int a = atoi(argv[2]);
  int b = atoi(argv[3]);
  
  int fd = open(argv[1], O_RDONLY);
  check_error(fd != -1, "open failed");
  
  check_error(lseek(fd, a, SEEK_SET) != -1, "lseek failed");
  
  char buffer[MAX_SIZE];
  int bytesRead = 0;
  while(b > 0){
    bytesRead = read(fd, buffer, MAX_SIZE);
    check_error(bytesRead != -1, "read failed");
    if(bytesRead == 0)
      break;
    check_error(write(STDOUT_FILENO, buffer, bytesRead < b ? bytesRead : b) != -1, "write failed");
    b -= bytesRead;
  }
  
  close(fd);
  
  exit(EXIT_SUCCESS);
}

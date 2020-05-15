#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 } while(0)
 
int main(int argc, char** argv){
  check_error(argc == 4, "Arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  check_error(S_ISREG(fInfo.st_mode), "must be reg file");
  
  int fd = open(argv[1], O_RDONLY);
  check_error(fd != -1, "open failed");
  
  int offset = atoi(argv[2]);
  int length = atoi(argv[3]);
  
  check_error(lseek(fd, offset, SEEK_SET) != -1, "lseek failed");
  
  char* buffer = malloc(length + 2);
  check_error(buffer != NULL, "malloc failed");
  
  int readBytes = 0;
  while(length > 0){
    readBytes = read(fd, buffer, length);
    check_error(readBytes != -1, "read failed");
    check_error(write(STDOUT_FILENO, buffer, readBytes) != -1, "write failed");
    length -= readBytes;    
  }
  
  close(fd);
  free(buffer);
  
  exit(EXIT_SUCCESS);
}
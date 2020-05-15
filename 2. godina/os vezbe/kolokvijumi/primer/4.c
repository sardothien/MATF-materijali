#define _XOPEN_SOURCE 700 

#include <sys/types.h>
#include <sys/stat.h>
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
 }while(0)

void osCatFileFromPos(const char* destPath, const char* srcPath, const off_t pos){
  
  char* path1 = realpath(destPath, NULL);
  char* path2 = realpath(srcPath, NULL);
  
  if(path1 != NULL && path2 != NULL && strcmp(path1, path2) == 0){
    fprintf(stderr, "dest and src must be different\n");
    exit(EXIT_FAILURE);
  }
  
  if(path1 != NULL)
    free(path1);
  if(path2 != NULL)
    free(path2);
  
  int srcFd, destFd;
  static int buffSize = 1<<13U;
  char* buffer = malloc(buffSize);
  check_error(buffer != NULL, "malloc failed");
  
  check_error((destFd = open(destPath, O_RDWR)) != -1, "open destFd failed");
  check_error((srcFd = open(srcPath, O_RDONLY)) != -1, "open srcFd failed");

  check_error(lseek(destFd, (off_t)pos, SEEK_SET) != -1, "lseek failed");
  
  int readBytes = 0;
  while((readBytes = read(srcFd, buffer, buffSize)) > 0)
    check_error(write(destFd, buffer, readBytes) == readBytes, "write failed");
  
  check_error(readBytes == 0, "read failed");
  
  free(buffer);
  close(destFd);
  close(srcFd);    
}
 
 
int main(int argc, char** argv){
  
  check_error(argc == 4, "Arguments");
  
  long pos = strtol(argv[3], 0, 10);
  
  osCatFileFromPos(argv[1], argv[2], (off_t)pos);
  
  exit(EXIT_SUCCESS);
}
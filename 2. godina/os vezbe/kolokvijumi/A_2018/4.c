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
 
#define MAX_SIZE (256)
 
int main(int argc, char** argv){
  check_error(argc == 3, "Arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  check_error(stat(argv[2], &fInfo) != -1, "stat failed");
  
  FILE* inF = fopen(argv[1], "r");
  check_error(inF != NULL, "fopen failed");
  int fd = open(argv[2], O_RDWR);
  check_error(fd != -1, "open failed");
  
  while(1){
    char word[MAX_SIZE];
    int x;
    int retValue = fscanf(inF, "%d%s", &x, word);
    if(retValue != 2)
      break;
    check_error(lseek(fd, x, SEEK_SET) != -1, "lseek failed");
    check_error(write(fd, word, strlen(word)) != -1, "write failed");
  }
  
  check_error(feof(inF), "feof failed");
  
  fclose(inF);
  close(fd);
  
  exit(EXIT_SUCCESS);
}
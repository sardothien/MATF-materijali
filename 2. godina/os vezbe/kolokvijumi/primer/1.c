#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
  }while(0)

#define MAX_STRING_SIZE (256)

bool osIsFileSmaller(const char* filePath, intmax_t fSize, char** fType) {
  
  errno = EINVAL;
  check_error(*fType == NULL, "must be NULL initialized");
  
  errno = 0;
  
  char* ft = malloc(MAX_STRING_SIZE);
  check_error(ft != NULL, "malloc failed");

  *fType = ft;

  struct stat fInfo;
  check_error(stat(filePath, &fInfo) != -1, "stat failed");
  
  switch (fInfo.st_mode & S_IFMT) {    
    case S_IFREG:  strcpy(ft, "Regular");
                   break;
    case S_IFDIR:  strcpy(ft, "Directory");
                   break;
    case S_IFLNK:  strcpy(ft, "Symbolic link");
                   break;
    case S_IFCHR:  strcpy(ft, "Character specific");
                   break;
    case S_IFBLK:  strcpy(ft, "Block specific");
                   break;
    case S_IFSOCK: strcpy(ft, "Socket");
                   break;
    case S_IFIFO:  strcpy(ft, "FIFO");
                   break;
    default:       perror("Unknown file format");
                   exit(EXIT_FAILURE);
  }
 
  return fInfo.st_size < fSize;
}

int main(int argc, char** argv) {
  check_error(argc == 3, "Arguments");
  
  char* fType = NULL
  long fSize = strtol(argv[2], 0, 10);
  
  bool result = osIsFileSmaller(argv[1], fSize, &fType);
 
  printf("%s %s\n", fType, result ? "true" : "false");

  free(fType);
  
  exit(EXIT_SUCCESS);
}  
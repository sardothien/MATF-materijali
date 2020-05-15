#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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

#define MAX_SIZE (1024)

char* getFileInfo(const char* fPath){
  struct stat fInfo;
  check_error(stat(fPath, &fInfo) != -1, "stat failed");
  
  static const char* fullAccess = "rwxrwxrwx";
  
  char* fileString = malloc(MAX_SIZE);
  check_error(fileString != NULL, "malloc failed");
  memset(fileString, 0, MAX_SIZE);
  
  switch(fInfo.st_mode & S_IFMT){
    case S_IFREG: fileString[0] = '-';
		  break;
    case S_IFDIR: fileString[0] = 'd';
		  break;
    default: fprintf(stderr, "must be dir or reg");
	     exit(EXIT_FAILURE);
  }
  
  int pos = 1;
  pos += sprintf(fileString + pos, "%s", fullAccess);
  
  if(!(fInfo.st_mode & S_IRUSR))
    fileString[1] = '-';
  if(!(fInfo.st_mode & S_IWUSR))
    fileString[2] = '-';
  if(!(fInfo.st_mode & S_IXUSR))
    fileString[3] = '-';
  
  if(!(fInfo.st_mode & S_IRGRP))
    fileString[4] = '-';
  if(!(fInfo.st_mode & S_IWGRP))
    fileString[5] = '-';
  if(!(fInfo.st_mode & S_IXGRP))
    fileString[6] = '-';
  
  if(!(fInfo.st_mode & S_IROTH))
    fileString[7] = '-';
  if(!(fInfo.st_mode & S_IWOTH))
    fileString[8] = '-';
  if(!(fInfo.st_mode & S_IXOTH))
    fileString[9] = '-';
  
  return fileString;  
}

int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  char* fileInfo = getFileInfo(argv[1]);
  fprintf(stdout, "%s\n", fileInfo);
  
  free(fileInfo);
  
  exit(EXIT_SUCCESS);
}
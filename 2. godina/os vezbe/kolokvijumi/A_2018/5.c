#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 }while(0)
 
void minMaxSize(const char* fPath, unsigned* min1, unsigned* max1){
  
  struct stat fInfo;
  check_error(lstat(fPath, &fInfo) != -1, "lstat 1 failed");
  
  if(S_ISREG(fInfo.st_mode)){
    if(fInfo.st_size < *min1)
      *min1 = fInfo.st_size;
    if(fInfo.st_size > *max1)
      *max1 = fInfo.st_size;
  }
  
  if(S_ISDIR(fInfo.st_mode)){
    DIR* dir = opendir(fPath);
    check_error(dir != NULL, "opendir failed");
    check_error(chdir(fPath) != -1, "chdir failed");
    struct dirent* entry = NULL;
    while(entry = readdir(dir)){
      if(!strcmp(".", entry->d_name) || !strcmp("..", entry->d_name))
	continue;
      minMaxSize(entry->d_name, min1, max1);
    }
    check_error(chdir("..") != -1, "chdir .. failed");
    check_error(closedir(dir) != -1, "closedir failed");
  }
}

int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  unsigned min = 0XFFFFFFFFU;
  unsigned max = 0;
  
  struct stat fInfo;
  check_error((lstat(argv[1], &fInfo) && S_ISDIR(fInfo.st_mode)) != -1, "lstat failed");
  
  minMaxSize(argv[1], &min, &max);
  printf("%u\n", max - min);
  
  exit(EXIT_SUCCESS);
}
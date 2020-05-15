#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 } while(0)
 
char* extension;

bool traverseDir(const char* fPath, int* sum){
  struct stat fInfo;
  if(stat(fPath, &fInfo) == -1)
    return false;
  
  char* ext = strrchr(fPath, '.');
  if(ext != NULL && !strcmp(extension, ext))
    (*sum)++;
  if(!S_ISDIR(fInfo.st_mode))
    return true;
  
  DIR* dir = opendir(fPath);
  if(dir == NULL)
    return false;
  if(chdir(fPath) == -1)
    return false;
  
  struct dirent* dirEntry = NULL;
  while((dirEntry = readdir(dir)) != NULL){
    if(!strcmp(dirEntry->d_name, "..") || !strcmp(dirEntry->d_name, "."))
      continue;
    bool success = traverseDir(dirEntry->d_name, sum);
    if(!success)
      return false;
  }
  
  if(chdir("..") == -1)
    return false;
  
  if(closedir(dir) == -1)
    return false;
  
  return true;
}
 
int main(int argc, char** argv){
  check_error(argc == 3, "Arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  check_error(S_ISDIR(fInfo.st_mode), "must be dir");
  
  extension = argv[2];
  int sum = 0;
  
  check_error(traverseDir(argv[1], &sum), "traverseDir failed");
  
  printf("%d\n", sum);
  
  exit(EXIT_SUCCESS);
}
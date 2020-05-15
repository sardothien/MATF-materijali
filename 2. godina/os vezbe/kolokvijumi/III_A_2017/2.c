#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 } while(0)

#define MAX_SIZE (256)

char* getFileInfo(const char* fPath){
  
  struct stat fInfo;
  check_error(stat(fPath, &fInfo) != -1, "stat failed");
  
  char* fileStr = malloc(MAX_SIZE);
  check_error(fileStr != NULL, "malloc failed");
  memset(fileStr, 0, MAX_SIZE);
  
  struct passwd* user = getpwuid(fInfo.st_uid);
  check_error(user != NULL, "getpwuid failed");
  
  struct group* grp = getgrgid(fInfo.st_gid);
  check_error(grp != NULL, "getgrgid failed");
  
  int pos = 0;
  pos += sprintf(fileStr + pos, "%s %s", user->pw_name, grp->gr_name);
  
  return fileStr;
}

 
int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  char* fileStr = getFileInfo(argv[1]);
  fprintf(stdout, "%s\n", fileStr);
  
  free(fileStr);
  
  exit(EXIT_SUCCESS);
}
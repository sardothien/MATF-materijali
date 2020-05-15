#define _XOPEN_SOURCE 700 

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 }while(0)

int osNumberOfUsersInGroup(const char* filePath){
  struct stat fInfo;
  check_error(stat(filePath, &fInfo) != -1, "stat failed");
  
  int users = 0;
  
  setpwent();
  
  struct passwd* userInfo = NULL;
  while((userInfo = getpwent()) != NULL)
    if(userInfo->pw_gid == fInfo.st_gid)
      users++;
  
  endpwent();
  
  return users;
}

int main(int argc, char** argv){
  
  check_error(argc == 2, "Arguments");
  
  int users = osNumberOfUsersInGroup(argv[1]);
  fprintf(stdout, "%d\n", users);

  
  exit(EXIT_SUCCESS);
}
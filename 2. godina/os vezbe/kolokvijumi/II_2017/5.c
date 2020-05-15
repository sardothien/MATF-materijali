#define _XOPEN_SOURCE 700

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ftw.h>
#include <time.h>
#include <limits.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
  }while(0)
  
#define SECS_PER_DAY (24*60*60)
#define UNUSED_VAR(x) ((void)x)
  
static char* dirPath = NULL;

bool osIsPublicFile(const char* fPath){
  struct stat fInfo;
  check_error(stat(fPath, &fInfo) != -1, "stat failed");
  check_error(S_ISREG(fInfo.st_mode), "not regular file");

  if ((fInfo.st_mode & S_IROTH) && (fInfo.st_mode & S_IWOTH))
   return true;
  else
   return false;
}

unsigned osNumOfDaysFileModified(const char* fPath) {  
  struct stat fInfo;
  check_error(stat(fPath, &fInfo) != -1, "stat failed");
  
  time_t now = time(NULL);
  check_error(now != -1, "time failed");
  
  unsigned days = (now - fInfo.st_mtime)/SECS_PER_DAY;
  return days;
}

void osMoveFile(const char* srcPath, const char* destPath) {  
  char *sPath = realpath(srcPath, NULL);
  char *dPath = realpath(destPath, NULL);
  
  check_error(sPath != NULL, "src file must exist");
  
  if (sPath != NULL && dPath != NULL) 
    check_error(strcmp(sPath, dPath) != 0, "same path");
  
  free(sPath);
  free(dPath);
  
  struct stat fInfo;
  check_error(stat(srcPath, &fInfo) != -1, "stat failed");
  
  int srcFd = open(srcPath, O_RDONLY);
  mode_t oldMask = umask(0);
  int destFd = open(destPath, O_CREAT | O_WRONLY | O_TRUNC, fInfo.st_mode);
  umask(oldMask);
  
  int bufSize = 1<<13u;
  char* buf = malloc(bufSize);
  
  check_error(buf != NULL, "allocation failed");
  
  int bytesRead = 0;
  
  while ((bytesRead = read(srcFd, buf, bufSize)) > 0)   
    check_error(write(destFd, buf, bytesRead) == bytesRead, "write failed");  
  
  check_error(bytesRead == 0, "read failed");
  
  free(buf);
  close(srcFd);
  close(destFd);
  
  check_error(unlink(srcPath) != -1, "unlink failed");
}

void osMakePublicDir(const char* fpath) {  
  mode_t oldMask = umask(0);  
  check_error(mkdir(fpath, 0777) != -1, "dir creation failed");
  umask(oldMask);
}

int processFile(const char* fPath, const struct stat *sb,
	        int typeflag, struct FTW* ftwbuf){
	      
  UNUSED_VAR(sb);
  if(typeflag == FTW_F){
    if(osIsPublicFile(fPath)){
      unsigned days = osNumOfDaysFileModified(fPath);
      if(days < 30){
	char* newPath = malloc(strlen(dirPath) + 2 + 
	      strlen(fPath + ftwbuf->base));
	strcpy(newPath, dirPath);
	strcpy(newPath, "/");
	strcpy(newPath, fPath + ftwbuf->base);
	
	osMoveFile(fPath, newPath);
	free(newPath);
      }
      else
	check_error(unlink(fPath) != -1, "unlink failed");
    }
  }
  
  return 0;
}

// ./5 ...
int main(int argc, char** argv){
  check_error(argc == 3, "Arguments");
  
  dirPath = argv[2];
  osMakePublicDir(argv[2]);
  
  check_error(nftw(argv[1], processFile, 50, 0) != -1, 
		  "nftw failed");
  
  exit(EXIT_SUCCESS);
}
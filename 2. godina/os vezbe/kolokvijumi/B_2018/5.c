#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <ftw.h>
#include <string.h>

#define check_error(expr, userMsg)\
 do{\
  if(!(expr)){\
    fprintf(stderr, "%s\n", userMsg);\
    exit(EXIT_FAILURE);\
  }\
 }while(0)
 
char* ext;

int processFile(const char* fPath, const struct stat* sb, int typeflag, struct FTW* ftwbuf){
  if(typeflag == FTW_F)
    if(ftwbuf->level >= 2 && ftwbuf->level <= 5){
      char* extension = strrchr(fPath, '.');
      if(extension != NULL && !strcmp(extension, ext))
	printf("%s\n", fPath + ftwbuf->base);
    }
  
  return 0;
}
 
int main(int argc, char** argv){
  check_error(argc == 3, "arguments");
  
  ext = argv[2];
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  check_error(S_ISDIR(fInfo.st_mode), "must be directory");
  
  check_error(nftw(argv[1], processFile, 50, 0) != -1, "nftw failed");
  
  exit(EXIT_SUCCESS);
}
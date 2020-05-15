#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include <errno.h>
#include <string.h>
#include <limits.h>
#include <pwd.h>
#include <ftw.h>
#include <utime.h>

#define UNUSED(x) ((void)x)
#define FILE_SIZE (500)
#define NO_OF_USERS (3)
#define MAX_STRING_SIZE (256)

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 }while(0)  

static char* destFilePath = NULL;

bool osIsFileSmaller(const char* filePath, intmax_t fSize, char** fType){
  
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

int osNumberOfUsersInGroup(const char* filePath){
 
 struct stat fInfo;
 check_error(stat(filePath, &fInfo) != -1, "stat failed");
 
 int users = 0;

 setpwent();
 
 struct passwd* entry = NULL;
 while((entry = getpwent()) != NULL)   
   if (entry->pw_gid == fInfo.st_gid)
     users++;

 endpwent();

 return users;
}

void osCatFileFromPos(const char* destPath, const char* srcPath, const off_t pos){
 
  char* path1 = realpath(destPath, NULL);
  char* path2 = realpath(srcPath, NULL);
  
  check_error(strcmp(path1, path2) != 0, "must be different");

  free(path1);
  free(path2);
  
  int srcFd, destFd;
  static int bufferSize = 1<<13U;
  char* buffer = malloc(bufferSize);
  check_error(buffer != NULL, "malloc failed");
  
  check_error((destFd = open(destPath, O_RDWR)) != -1, "dest open failed");
  check_error((srcFd = open(srctPath,  O_RDONLY)) != -1, "src open failed");
  
  check_error(lseek(destFd, (off_t)pos, SEEK_SET) != -1, "lseek failed");
    
  int readBytes = 0;
  while((readBytes = read(srcFd, buffer, bufferSize)) > 0)
    check_error(write(destFd, buffer, readBytes) == readBytes, "write failed");

  check_error(readBytes == 0, "read failed");
  
  free(buffer);
  close(destFd);
  close(srcFd);
}

int processFile(const char* fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf){
  UNUSED(ftwbuf);
  
  if(typeflag == FTW_F){   
 
   char *str = NULL;
   bool lowerThan = osIsFileSmaller(fpath, FILE_SIZE, &str);
   free(str);

   if(!lowerThan){
      int users = osNumberOfUsersInGroup(fpath);      
      if(users > NO_OF_USERS){
	char* path1 = realpath(fpath, NULL);
	char* path2 = realpath(destFilePath, NULL);

	int fd = 0;
	check_error((fd = open(path2, O_RDWR)) != -1, "open failed");

	off_t pos = 0;
	check_error((pos = lseek(fd, 0, SEEK_END)) != -1, "lseek failed");

	close(fd);
	
	if(strcmp(path1, path2) == 0){
	  free(path1);
	  free(path2);
	  return 0;
	}
	
	osCatFileFromPos(path2, fpath, pos);

	free(path1);
	free(path2);
      }
      else if(users < NO_OF_USERS){	
	struct utimbuf times;
	times.actime = sb->st_atime - 3*60*60*24;
	times.modtime = sb->st_mtime;	
        
	check_error(utime(fpath, &times) != -1, "utime failed");
      }
    }
  }
  
  return 0;
}

void osMakeFile(const char* filePath){  
  static mode_t defaultMode = 0733;
  int fd = 0;  
  
  check_error((fd = open(filePath, O_WRONLY | O_CREAT | O_EXCL, defaultMode)) >= 0, "open fd failed");
  
  close(fd);
}

int main(int argc, char** argv){  

  check_error(argc == 3, "Arguments");
  
  char* str = NULL;
  
  osIsFileSmaller(argv[1], FILE_SIZE, &str);
  check_error(strcmp(str, "Directory") == 0, "must be directory");

  free(str);
 
  destFilePath = argv[2];
  
  mode_t oldMask = umask(0);
  osMakeFile(destFilePath); 
  umask(oldMask);
  
  check_error(nftw(argv[1], processFile, 50, 0) != -1, "nftw failed");
  
  exit(EXIT_SUCCESS);
}   
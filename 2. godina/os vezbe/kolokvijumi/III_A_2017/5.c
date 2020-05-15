#define _XOPEN_SOURCE 700
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ftw.h>

#define check_error(expr, userMsg)\
 do{\
   if(!(expr)){\
     fprintf(stderr, "%s\n", userMsg);\
     exit(EXIT_FAILURE);\
   }\
 } while(0)
 
#define UNUSED_VAR(x) ((void)x)
 
int total = 0;
int reg_cnt = 0;
int dir_cnt = 0;
int fifo_cnt = 0;
int chr_cnt = 0;
int blk_cnt = 0;
int sck_cnt = 0;
int lnk_cnt = 0;
  
int processDir(const char* fPath, const struct stat* sb, 
	       int typeflag, struct FTW* ftwbuf){
  UNUSED_VAR(typeflag);
  UNUSED_VAR(fPath);
  UNUSED_VAR(ftwbuf);
  
  if(S_ISREG(sb->st_mode))
    reg_cnt++;
  else if(S_ISDIR(sb->st_mode))
    dir_cnt++;
  else if(S_ISCHR(sb->st_mode))
    chr_cnt++;
  else if(S_ISBLK(sb->st_mode))
    blk_cnt++;
  else if(S_ISFIFO(sb->st_mode))
    fifo_cnt++;
  else if(S_ISLNK(sb->st_mode))
    lnk_cnt++;
  else if(S_ISSOCK(sb->st_mode))
    sck_cnt++;
    
  total++;
  
  return 0;
}

int main(int argc, char** argv){
  check_error(argc == 2, "Arguments");
  
  check_error(nftw(argv[1], processDir, 50, FTW_PHYS) != -1, "nftw failed");
  
  printf("%d %d %d %d %d %d %d %d\n", reg_cnt, dir_cnt, 
			      chr_cnt, blk_cnt, lnk_cnt, 
			      fifo_cnt, sck_cnt, total);
  
  exit(EXIT_SUCCESS);
}
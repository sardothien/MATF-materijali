#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>

#define check_error(expr, userMsg)\
 do{\
  if(!(expr)){\
    fprintf(stderr, "%s\n", userMsg);\
    exit(EXIT_FAILURE);\
  }\
 }while(0)
 
int main(int argc, char** argv){
  check_error(argc == 3, "arguments");
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  
  mode_t oldMode = fInfo.st_mode;
  
  switch(argv[2][0]){
    case 'u':
      if(argv[2][1] == '-'){
	if(argv[2][2] == 'r')
	  oldMode &= ~S_IRUSR;
	else if(argv[2][2] == 'w')
	  oldMode &= ~S_IWUSR;
	else if(argv[2][2] == 'x')
	  oldMode &= ~S_IXUSR;
	else
	  exit(EXIT_FAILURE);
      }
      else if(argv[2][1] == '+'){
	if(argv[2][2] == 'r')
	  oldMode |= S_IRUSR;
	else if(argv[2][2] == 'w')
	  oldMode |= S_IWUSR;
	else if(argv[2][2] == 'x')
	  oldMode |= S_IXUSR;
	else
	  exit(EXIT_FAILURE);
      }
      else
	exit(EXIT_FAILURE);
      break;
      
    case 'g':
      if(argv[2][1] == '-'){
	if(argv[2][2] == 'r')
	  oldMode &= ~S_IRGRP;
	else if(argv[2][2] == 'w')
	  oldMode &= ~S_IWGRP;
	else if(argv[2][2] == 'x')
	  oldMode &= ~S_IXGRP;
	else
	  exit(EXIT_FAILURE);
      }
      else if(argv[2][1] == '+'){
	if(argv[2][2] == 'r')
	  oldMode |= S_IRGRP;
	else if(argv[2][2] == 'w')
	  oldMode |= S_IWGRP;
	else if(argv[2][2] == 'x')
	  oldMode |= S_IXGRP;
	else
	  exit(EXIT_FAILURE);
      }
      else
	exit(EXIT_FAILURE);
      break;
      
    case 'o':
      if(argv[2][1] == '-'){
	if(argv[2][2] == 'r')
	  oldMode &= ~S_IROTH;
	else if(argv[2][2] == 'w')
	  oldMode &= ~S_IWOTH;
	else if(argv[2][2] == 'x')
	  oldMode &= ~S_IXOTH;
	else
	  exit(EXIT_FAILURE);
      }
      else if(argv[2][1] == '+'){
	if(argv[2][2] == 'r')
	  oldMode |= S_IROTH;
	else if(argv[2][2] == 'w')
	  oldMode |= S_IWOTH;
	else if(argv[2][2] == 'x')
	  oldMode |= S_IXOTH;
	else
	  exit(EXIT_FAILURE);
      }
      else
	exit(EXIT_FAILURE);
      break;
    
    default: exit(EXIT_FAILURE);
  }
  
  check_error(chmod(argv[1], oldMode) != -1, "chmod failed");
  
  exit(EXIT_SUCCESS);
}
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
 
void processFile(const char* fPath, const char* mode){
  int in, out;
  
  switch(mode[1]){
    case 'r': in = open(fPath, O_RDONLY);
	      check_error(in != -1, "open r failed");
	      out = STDOUT_FILENO;
	      break;
    case 'w': out = open(fPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	      check_error(out != -1, "open w failed");
	      in = STDIN_FILENO;
	      break;
    case 'a': out = open(fPath, O_WRONLY | O_CREAT | O_APPEND, 0644);
	      check_error(out != -1, "open a failed");
	      in = STDIN_FILENO;
	      break;
  }
  
  size_t buffSize = 1<<13U;
  char* buf = malloc(buffSize);
  check_error(buf != NULL, "malloc failed");
  
  int readBytes = 0;
  while((readBytes = read(in, buf, buffSize)) > 0){
    if(write(out, buf, readBytes) != readBytes){
      free(buf);
      fprintf(stderr, "write failed");
      exit(EXIT_FAILURE);
    }
  }
  
  check_error(readBytes == 0, "read failed");
  
  free(buf);
  
  switch(mode[1]){
    case 'r': close(in);
              break;
    case 'w': close(out);
   	      break;
    case 'a': close(out);
	      break;
  }  
}
  
int main(int argc, char** argv){
  check_error(argc == 3, "Arguments");
  
  check_error(!strcmp(argv[1], "-r") || !strcmp(argv[1], "-w") 
           || !strcmp(argv[1], "-a"), "Invalid argument");
  
  processFile(argv[2], argv[1]);
    
  exit(EXIT_SUCCESS);
}
#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <ctype.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
#define RD_END (0)
#define WR_END (1)

int main(int argc, char** argv){
  check_error(argc == 1, "arguments");
  
  while(1){
  
    int par2cld[2], cld2par[2];
    
    check_error(pipe(par2cld) != -1, "pipe failed");
    check_error(pipe(par2cld) != -1, "pipe failed");
    
    pid_t childPid = fork();
    check_error(childPid != -1, "fork failed");
    
    if(childPid > 0){
      close(par2cld[RD_END]);
      close(cld2par[WR_END]);
      
      char word[64];
      char letter[64];
      char buffer[64*2];
      
      int n = fscanf(stdin, "%s%s", word, letter);
      if(n != 2)
	break;
      
      memset(buffer, 0, 512);
      
      if(strlen(letter) > 1){
	fprintf(stderr, "wrong arg");
	continue;
      }
      
      if(letter[0] == 'l' || letter[0] == 'u' || letter[0] == 'r')
	sprintf(buffer, "%s %s", word, letter);
      else{
	fprintf(stderr, "wrong arg");
	continue;
      }
      
      check_error(write(par2cld[WR_END], buffer, 64*2) != -1, "write failed");
      memset(buffer, 0, 64*2);
      check_error(read(cld2par[RD_END], buffer, 64*2) != -1, "read failed");
      
      printf("%s\n", buffer);
      
      close(par2cld[WR_END]);
      close(cld2par[RD_END]);
    }
    else{
      
      close(par2cld[WR_END]);
      close(cld2par[RD_END]);
      
      char bufferR[64*2], bufferS[64*2];
      memset(bufferR, 0, 64*2);
      memset(bufferS, 0, 64*2);
      
      check_error(read(par2cld[RD_END], bufferR, 64*2) != -1, "read failed");
      
      int pos = (int)(strchr(bufferR, ' ') - bufferR);
      
      if(bufferR[pos+1] == 'l')
	for(int i = 0; i < pos; i++)
	  bufferS[i] = tolower(bufferR[i]);
      else if(bufferR[pos+1] == 'u')
	for(int i = 0; i < pos; i++)
	  bufferS[i] = toupper(bufferR[i]);
      else if(bufferR[pos+1] == 'r')
	for(int i = 0; i < pos; i++)
	  bufferS[i] = tolower(bufferR[pos-i-1]);
      
      check_error(write(cld2par[WR_END], bufferS, 2*64) != -1, "write failed");
      
      close(cld2par[WR_END]);
      close(par2cld[RD_END]);
      
      exit(EXIT_SUCCESS);
    }
  
    check_error(wait(NULL) != -1, "wait failed");
  }
  
  exit(EXIT_SUCCESS);
}
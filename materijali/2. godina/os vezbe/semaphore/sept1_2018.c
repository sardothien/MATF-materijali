#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <signal.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
#define ARRAY_MAX (1024)
typedef struct {
  sem_t dataProcessingFinished;
  int array[ARRAY_MAX];
  unsigned arrayLen;
} OsInputData;

void *getBlock(const char* fPath, unsigned *size){
  
  int memFd = shm_open(fPath, O_RDWR, 0600);
  check_error(memFd != -1, "shm_open failed");
  
  struct stat fInfo;
  check_error(fstat(memFd, &fInfo) != -1, "fstat failed");
  *size = fInfo.st_size;
  
  void *addr = mmap(NULL, *size, PROT_READ | PROT_WRITE, MAP_SHARED, memFd, 0);
  check_error(addr != MAP_FAILED, "mmap failed");
  
  close(memFd);
  
  return addr;
}

int sig1 = 0, sig2 = 0;

void signalHandler(int signum){
  switch(signum){
    case SIGUSR1: sig1 = 1; break;
    case SIGUSR2: sig2 = 1; break;
  }
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  unsigned size = 0;
  
  OsInputData *data = getBlock(argv[1], &size);
  
  check_error(signal(SIGUSR1, signalHandler) != SIG_ERR, "sig1 failed");
  check_error(signal(SIGUSR2, signalHandler) != SIG_ERR, "sig2 failed");
  
  do{
    pause();
    
    if(sig1){
      for(int i = 0; i < data->arrayLen; i++)
	data->array[i] = -data->array[i];
      
      sig1 = 0;
    }
    else if(sig2){
      for(int i = 0; i < data->arrayLen; i++)
	data->array[i] *= 2;
      
      sig2 = 0;
    }
    
  }while(0);
  
  for(int i = 0; i < data->arrayLen; i++)
	printf("%d ", data->array[i]);
  printf("\n");
  
  check_error(sem_post(&(data->dataProcessingFinished)) != -1, "sem_wait failed");
  
  check_error(munmap(data, size) != -1, "munmap failed");
  
  exit(EXIT_SUCCESS);
}
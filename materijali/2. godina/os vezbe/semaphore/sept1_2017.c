#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
#define ARRAY_MAX (1024)
typedef struct {
  sem_t inDataReady;
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

int pow3(int x) {
  if(x == 1)
    return 1;
  else if(x % 3 == 0)
    return pow3(x/3);
  else
    return 0;
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  unsigned size = 0;
  
  OsInputData *data = getBlock(argv[1], &size);
  
  check_error(sem_wait(&(data->inDataReady)) != -1, "sem_wait failed");
  
  for(int i = 0; i < data->arrayLen; i++)
    if(pow3(data->array[i]))
      printf("%d\n", data->array[i]);
  
  check_error(munmap(data, size) != -1, "munmap failed");
  
  exit(EXIT_SUCCESS);
}
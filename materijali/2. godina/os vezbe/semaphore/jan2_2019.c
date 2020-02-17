#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <stdbool.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

#define MAX (1024)
typedef struct {
  sem_t inDataReady;
  int array[MAX];
  unsigned arrayLen;
} OsInputData;

bool fourOnes(int x) {
  unsigned mask = 1 << ((sizeof (int))* 8 - 1);
  int count = 0;
    
  while(mask) {
    if(mask & x) 
      count++;
    mask >>= 1;
  }

  return count >= 4;
}

void *getBlock(int fd, off_t size){
  
  void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  check_error(addr != MAP_FAILED, "mmap failed");
 
  return addr;
}

int main(int argc, char** argv){
  check_error(argc == 3, "arguments");
  
  int memIn = shm_open(argv[1], O_RDWR, 0600);
  check_error(memIn != -1, "shm_open failed");
  
  int memOut = shm_open(argv[2], O_RDWR, 0600);
  check_error(memOut != -1, "shm_open failed");
  
  struct stat fInfo;
  check_error(fstat(memIn, &fInfo) != -1, "fstat failed");
  off_t size1 = fInfo.st_size;
  check_error(fstat(memOut, &fInfo) != -1, "fstat failed");
  off_t size2 = fInfo.st_size;
  
  OsInputData *data1 = getBlock(memIn, size1);
  OsInputData *data2 = getBlock(memOut, size2);
  
  close(memIn);
  close(memOut);
  
  check_error(sem_wait(&data1->inDataReady) != -1, "sem_wait failed");
  
  unsigned newLen = 0;
  
  for(int i = 0; i < data1->arrayLen; i++)
    if(fourOnes(data1->array[i]))
      data2->array[newLen++] = data1->array[i];
    
  data2->arrayLen = newLen;
  
  check_error(sem_post(&(data2->inDataReady)) != -1, "sem_wait failed");
  
  check_error(munmap(data1, size1) != -1, "munmap failed");
  check_error(munmap(data2, size2) != -1, "munmap failed");
  
  exit(EXIT_SUCCESS);
}
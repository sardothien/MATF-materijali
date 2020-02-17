#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
// Uvek isto:
#define MAX_SIZE (1024)
typedef struct {
  int niz[MAX_SIZE];
  int n;  
}sharedData_t;

void *createBlock(const char *fPath, unsigned size){
  
  int memFd = shm_open(fPath, O_RDWR | O_CREAT, 0600);
  check_error(memFd != -1, "shm_open failed");
  
  check_error(ftruncate(memFd, size) != -1, "ftruncate failed");
  
  void *addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, memFd, 0);
  check_error(addr != MAP_FAILED, "mmap failed");
  
  close(memFd);
  
  return addr;
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  unsigned size = 0;
  
  sharedData_t *data = createBlock(argv[1], sizeof(sharedData_t));
  
  data->n = 10;
  for(int i = 0; i < data->n; i++)
    data->niz[i] = i;
  
  check_error(munmap(data, sizeof(sharedData_t)) != -1, "munmap failed");
  
  exit(EXIT_SUCCESS);
}
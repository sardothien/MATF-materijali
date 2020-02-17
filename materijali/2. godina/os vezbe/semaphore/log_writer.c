#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <string.h>
#include <sys/mman.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

// Uvek isto
#define MAX (1024)
typedef struct {
  char buffer[MAX];
  sem_t semRead;
  sem_t semWrite;
}sharedData_t;

void *createBlock(const char* fPath, unsigned size){
  
  int memFd = shm_open(fPath, O_RDWR, 0600);
  check_error(memFd != -1, "shm_open failed");
  
  check_error(ftruncate(memFd, size) != -1, "ftruncate failed");
  
  void* addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, memFd, 0);
  check_error(addr != MAP_FAILED, "mmap failed");
  
  close(memFd);
  
  return addr;
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
    
  sharedData_t* data = createBlock(argv[1], sizeof(sharedData_t));
  
  check_error(sem_init(&(data->semRead), 1, 0) != -1, "sem_init 1 failed");
  check_error(sem_init(&(data->semWrite), 1, 1) != -1, "sem_init 2 failed");
  
  
  char buf[MAX];
  
  do{
    scanf("%s", buf);
    
    check_error(sem_wait(&(data->semWrite)) != -1, "sem_wait failed");
    
    strcpy(data->buffer, buf);
    
    check_error(sem_post(&(data->semRead)) != -1, "sem_post failed");
    
  }while(strcmp(buf, "quit"));
  
  check_error(munmap(data, sizeof(sharedData_t)) != -1, "munmap failed");
  
  exit(EXIT_SUCCESS);
}
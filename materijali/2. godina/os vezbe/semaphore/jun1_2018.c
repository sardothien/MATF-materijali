#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <math.h>
#include <sys/mman.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)

#define MAX (1024)
typedef struct {
  sem_t ready;
  sem_t done;
  double points[MAX];
  int nPoints;
} OsInputData;

void* getBlock(const char* fPath, unsigned* size){
  int memFd = shm_open(fPath, O_RDWR, 0600);
  check_error(memFd != -1, "shm_open failed");
  
  struct stat fInfo;
  check_error(fstat(memFd, &fInfo) != -1, "fstat failed");
  *size = fInfo.st_size;
  
  void* addr = mmap(NULL, *size, PROT_READ | PROT_WRITE, MAP_SHARED, memFd, 0);
  check_error(addr != MAP_FAILED, "mmap failed");
  
  close(memFd);
  
  return addr;
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  unsigned size = 0;
  OsInputData* data = getBlock(argv[1], &size);
  
  double distance = 0;
  
  check_error(sem_wait(&(data->ready)) != -1, "sem_wait failed");
  
  if(data->nPoints > 1){
    distance = (data->points[0] - data->points[2])*(data->points[0] - data->points[2])
	     + (data->points[1] - data->points[3])*(data->points[1] - data->points[3]);
    for(int i = 0; i < data->nPoints; i++){
      for(int j = i+1; j < data->nPoints; j++){
	double tmp = (data->points[i*2] - data->points[j*2])*(data->points[i*2] - data->points[j*2])
		   + (data->points[i*2+1] - data->points[j*2+1])*(data->points[i*2+1] - data->points[j*2+1]);
	if(tmp < distance)
	  distance = tmp;
      }
    }
  }
  
  check_error(sem_post(&(data->done)) != -1, "sem_post failed");
  
  printf("%lf\n", sqrt(distance));
  
  check_error(munmap(data, size) != -1, "munmap failed");
  
  exit(EXIT_SUCCESS);
}
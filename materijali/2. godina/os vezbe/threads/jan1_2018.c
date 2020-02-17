#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>

#define check_error(expr, userMsg)\
  do{\
    if(!(expr)){\
      fprintf(stderr, "%s\n", userMsg);\
      exit(EXIT_FAILURE);\
    }\
  } while(0)
  
#define check_errorP(threadErr, userMsg)\
  do{\
    int _err = threadErr;\
    if(_err > 0){\
      errno = _err;\
      check_error(0, userMsg);\
    }\
  }while(0)
  
typedef struct {
  int idx;
}threadData_t;

int globalSum = 0;
int N, K;
const char* W;
const char* fPath;
pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;

void* threadFunc(void* arg){
  threadData_t* data = (threadData_t*)arg;
  
  int fd = open(fPath, O_RDONLY);
  check_error(fd != -1, "open failed");
  
  int localSum = 0;
  off_t start = data->idx * (N/K);
  off_t end = (data->idx + 1) * (N/K) - (strlen(W) + 1);
  off_t curr_off = start;
  
  int size  = strlen(W) + 1;
  char* buffer = malloc(size);
  check_error(buffer != NULL, "malloc failed");
  
  while(curr_off <= end){
    check_error(lseek(fd, curr_off, SEEK_SET) != -1, "lseek failed");
    
    check_error(read(fd, buffer, size - 1) != -1, "read failed");
    
    buffer[size-1] = 0;
    
    if(strcmp(buffer, W) == 0)
      localSum++;
    
    curr_off += 1;
  }
  
  close(fd);
  free(buffer);
  
  check_errorP(pthread_mutex_lock(&globalLock), "lock failed");
  globalSum += localSum;
  check_errorP(pthread_mutex_unlock(&globalLock), "unlock failed");
  
  return NULL;  
}

// path chars num
int main(int argc, char** argv){
  check_error(argc == 4, "arguments");
  
  fPath = argv[1];
  W = argv[2];
  K = atoi(argv[3]);
  
  struct stat fInfo;
  check_error(stat(argv[1], &fInfo) != -1, "stat failed");
  N = fInfo.st_size;
  
  pthread_t* tids = malloc(K*sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadData_t* args = malloc(K*sizeof(threadData_t));
  check_error(args != NULL, "malloc failed");
  
  for(int i = 0; i < K; i++){
    args[i].idx = i;
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "create failed");
  }
  
  for(int i = 0; i < K; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  printf("%d\n", globalSum);
  
  free(args);
  free(tids);  
  
  exit(EXIT_SUCCESS);
}
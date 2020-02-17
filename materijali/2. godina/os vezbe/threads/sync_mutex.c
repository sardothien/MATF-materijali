#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
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
  } while(0)

typedef struct {
  int idx;
  char* path;
} threadData_t;

int globalSum = 0;
pthread_mutex_t globalLock; 

void* threadFunc(void* arg){
  
  threadData_t* data = (threadData_t*)arg;
  
  FILE* f = fopen(data->path, "r");
  check_error(f != NULL, "fopen failed");
  
  int byteCount = 0;
  while(fgetc(f) != EOF)
    byteCount++;
  
  check_errorP(pthread_mutex_lock(&globalLock), "mutex lock failed");
  globalSum += byteCount;
  check_errorP(pthread_mutex_unlock(&globalLock), "mutex unlock failed");
  
  fclose(f);
  
  return NULL;
}
  
int main(int argc, char** argv){
  
  check_error(argc > 1, "arguments");
  
  int num = argc - 1;
  
  check_errorP(pthread_mutex_init(&globalLock, NULL), "mutex init failed");
  
  pthread_t* tids = malloc(num*sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadData_t* args = malloc(num*sizeof(threadData_t));
  check_error(args != NULL, "malloc failed");
  
  for(int i = 0; i < num; i++){
    args[i].idx = i;
    args[i].path = argv[i+1];
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "pthread_create failed");
  }
  
  for(int i = 0; i < num; i++){
    check_errorP(pthread_join(tids[i], NULL), "pthread_join failed");
  }
  
  printf("Ukupno karaktera: %d\n", globalSum);
    
  free(args);
  free(tids);
  
  check_errorP(pthread_mutex_destroy(&globalLock), "mutex destroy failed");
  
  exit(EXIT_SUCCESS);
}
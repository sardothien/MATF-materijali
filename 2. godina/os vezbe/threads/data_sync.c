#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
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
  }while(0)
  
typedef struct {
  int idx;
}threadData_t;

int globalCount = 0;
int globalArray[256];

pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t globalSignaler = PTHREAD_COND_INITIALIZER;

void *threadFunc(void* arg){
  threadData_t *data = (threadData_t*)arg;
  
  while(1){
    pthread_mutex_lock(&globalLock);
    
    while(globalCount == 0)
      pthread_cond_wait(&globalSignaler, &globalLock);
    
    if(globalCount == -1){
      pthread_mutex_unlock(&globalLock);
      break;
    }
    
    int localSum = 0;
    for(int i = 0; i < globalCount; i++)
      localSum += globalArray[i]*globalArray[i];
    
    printf("Thread: %d. Skalarni proizvod: %d\n", data->idx, localSum);
    
    globalCount = 0;
    
    pthread_mutex_unlock(&globalLock);
  }
  
  printf("Thread %d ended.\n", data->idx);
  
  return NULL;
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  int num = atoi(argv[1]);
  
  pthread_t* tids = malloc(num * sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadData_t* args = malloc(num * sizeof(threadData_t));
  check_error(args != NULL, "malloc failed");
  
  for(int i = 0; i < num; i++){
    args[i].idx = i;
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "pthread_create failed");
  }
  
  char* line = NULL;
  size_t lineLen = 0;
  
  while(getline(&line, &lineLen, stdin) != -1){
    pthread_mutex_lock(&globalLock);
    int bytesRead = sscanf(line, "%d", &globalCount);
    
    if(globalCount == -1){
      pthread_mutex_unlock(&globalLock);
      pthread_cond_broadcast(&globalSignaler);
      break;
    }
    
    for(int i = 0; i < globalCount; i++)
      bytesRead += sscanf(line + bytesRead, "%d", &globalArray[i]);
    
    pthread_mutex_unlock(&globalLock);
    pthread_cond_signal(&globalSignaler);    
  }
  
  for(int i = 0; i < num; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  free(line);
  free(tids);
  free(args);
  
  pthread_cond_destroy(&globalSignaler);
  pthread_mutex_destroy(&globalLock);
  
  exit(EXIT_SUCCESS);
}
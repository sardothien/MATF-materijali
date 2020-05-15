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

void *threadFunc(void* arg){
  threadData_t* data = (threadData_t*) arg;
  printf("Thread %d started.\n", data->idx);
  
  threadData_t* outData = malloc(sizeof(threadData_t));
  check_error(outData != NULL, "malloc failed");
  
  outData->idx = 50*data->idx;
  
  return outData;
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
  
  for(int i = 0; i < num; i++){
    threadData_t* data = NULL;
    check_errorP(pthread_join(tids[i], (void**)&data), "pthread_join failed");
    printf("Thread %d ended.\n", data->idx);
    free(data);
  }
  
  free(args);
  free(tids);
  
  exit(EXIT_SUCCESS);
}
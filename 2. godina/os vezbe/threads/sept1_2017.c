#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <stdint.h>

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
  
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
unsigned n = 0;
int* mat = NULL;
int vertrex = 0;
unsigned max = 0;

void* threadMin(void* arg){
  unsigned vertexIdx = (unsigned)(intptr_t)arg;
  unsigned inDegree = 0;
  for(unsigned i = 0; i < n; i++)
    inDegree += mat[i*n+vertexIdx];
  
  check_errorP(pthread_mutex_lock(&lock), "lock failed");
  
  if(inDegree > max){
    max = inDegree;
    vertrex = vertexIdx;
  }
  
  check_errorP(pthread_mutex_unlock(&lock), "unlock failed");
  
  return NULL;
}

int main(){
  
  scanf("%u", &n);
  
  mat = malloc(n*n*sizeof(int*));
  check_error(mat != NULL, "malloc failed");
  
  for(unsigned i = 0; i < n*n; i++)
    scanf("%d", &mat[i]);
  
  pthread_t* tids = malloc(n*sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  for(unsigned i = 0; i < n; i++)
    check_errorP(pthread_create(tids+i, NULL, threadMin, (void*)(intptr_t)i), "pthread_create failed");
  
  for(unsigned i = 0; i < n; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  free(tids);
  free(mat);
  check_errorP(pthread_mutex_destroy(&lock), "destroy failed");
  
  printf("%d\n", vertrex);  
  
  exit(EXIT_SUCCESS);
}
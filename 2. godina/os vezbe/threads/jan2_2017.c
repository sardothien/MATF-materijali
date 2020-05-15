#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>

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
  int colNumber;
} threadFunc_t;

int** mat;
int m, n;
int max = 0;
int initialized = 0;
pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;

void* threadFunc(void* arg) {
  threadFunc_t* data = (threadFunc_t*)arg;
  
  int localSum = 0;
  int i = 0;
  for(i = 0; i < m; i++)
    localSum += mat[i][data->colNumber];
  
  check_errorP(pthread_mutex_lock(&globalLock), "lock failed");
  
  if(initialized){
    if(localSum > max)
      max = localSum;
  }
  else{
    initialized = 1;
    max = localSum;
  }
  
  check_errorP(pthread_mutex_unlock(&globalLock), "unlock failed");
  
  return NULL;
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  int i = 0, j = 0;
  FILE *in = fopen(argv[1], "r");
  check_error(in != NULL, "fopen failed");
	
  fscanf(in, "%d%d", &m, &n);  

  mat = malloc(m * sizeof(int*));
  check_error(mat != NULL, "malloc failed");
  
  for(i = 0; i < m; i++){
    mat[i] = malloc(n * sizeof(int));
    check_error(mat[i] != NULL, "malloc failed");
  }
  
  for(i = 0; i < m; i++)
    for(j = 0; j < n; j++)
      fscanf(in, "%d", &mat[i][j]);
    
  fclose(in);
  
  pthread_t* tids = malloc(n * sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadFunc_t* args = malloc(n * sizeof(threadFunc_t));
  check_error(args != NULL, "malloc failed");
  
  for(i = 0; i < n; i++){
    args[i].colNumber = i;
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "pthread_create failed");
  }
  
  for(i = 0; i < n; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  check_error(pthread_mutex_destroy(&globalLock), "destroy failed");
  
  printf("%d\n", max);
  
  for(i = 0; i < m; i++)
    free(mat[i]);
  free(mat);
  
  free(args);
  free(tids);
  
  exit(EXIT_SUCCESS);
}

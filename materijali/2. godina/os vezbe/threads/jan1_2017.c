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
  
typedef struct{
  int tid;
  int row;
}threadData_t;

double globalMin = 0;
pthread_mutex_t globalLock;
int N = 0, M = 0;
double** mat;

void *threadFunc(void* arg){
  threadData_t* data = (threadData_t*)arg;
  
  double min = mat[data->row][0];
  int i = 0;
  for(i = 1; i < M; i++)
    if(mat[data->row][i] < min)
      min = mat[data->row][i];
    
  check_errorP(pthread_mutex_lock(&globalLock), "lock failed");
  
  if(min < globalMin)
    globalMin = min;
  
  check_errorP(pthread_mutex_unlock(&globalLock), "unlock failed");
  
  return NULL;
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  FILE *in = fopen(argv[1], "r");
  check_error(in != NULL, "fopen failed");
  
  fscanf(in, "%d%d", &N, &M);
  
  int i = 0, j = 0;
  mat = malloc(N * sizeof(double*));
  check_error(mat != NULL, "malloc failed");
  
  for(i = 0; i < N; i++){
    mat[i] = malloc(M * sizeof(double));
    check_error(mat[i] != NULL, "malloc failed");
  }
  
  for(i = 0; i < N; i++)
    for(j = 0; j < M; j++)
      fscanf(in, "%lf", &mat[i][j]);
    
  fclose(in);
  
  pthread_t* tids = malloc(N * sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadData_t* args = malloc(N * sizeof(threadData_t));
  check_error(args != NULL, "malloc failed");
  
  check_errorP(pthread_mutex_init(&globalLock, NULL), "init failed");
  
  for(i = 0; i < N; i++){
    args[i].tid = (i+1);
    args[i].row = i;
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "create failed");
  }
  
  for(i = 0; i < N; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  check_errorP(pthread_mutex_destroy(&globalLock), "destroy failed");
  
  printf("%lf\n", globalMin);
  
  for(i = 0; i < N; i++)
    free(mat[i]);
  free(mat);
  
  free(tids);
  free(args);  
  
  exit(EXIT_SUCCESS);
}
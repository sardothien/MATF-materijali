#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
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
  int idx;
} threadFunc_t;
  
double** mat;
double p;
int m, n;
double globalSum = 0;
pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;

void* threadFunc(void* arg){
  threadFunc_t* args = (threadFunc_t*)arg;
  
  double localSum = 0;
  for(int i = 0; i < n; i++)
    localSum += pow(fabs(mat[args->idx][i]), p);
  
  check_errorP(pthread_mutex_lock(&globalLock), "lock failed");
  globalSum += localSum;
  check_errorP(pthread_mutex_unlock(&globalLock), "unlock failed");
  
  return NULL;
}

int main(int argc, char** argv){
  check_error(argc == 1, "arguments");
  
  int i, j;
  scanf("%lf%d%d", &p, &m, &n);
  
  mat = malloc(sizeof(double*)*m);
  check_error(mat != NULL, "...");
	
  for(i = 0; i < m; i++){
    mat[i] = malloc(sizeof(double)*n);
    check_error(mat[i] != NULL, "...");
    for(j = 0; j < n; j++)
      scanf("%lf", &mat[i][j]);
  }
  
  pthread_t* tids = malloc(m*sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadFunc_t* args = malloc(m*sizeof(threadFunc_t));
  check_error(args != NULL, "malloc failed");
  
  for(int i = 0; i < m; i++){
    args[i].idx = i;
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "create failed");
  }
  
  for(int i = 0; i < m; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  printf("%lf\n", pow(globalSum, 1.0/p));
  
  for(int i = 0; i < m; i++)
    free(mat[i]);
  free(mat);
  
  free(args);
  free(tids);
  
  exit(EXIT_SUCCESS);
}
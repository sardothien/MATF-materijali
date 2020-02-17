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
  } while(0)
  
typedef struct {
  int row;
  int col;
} threadFunc_t;

int** matA;
int** matB;
int** matC;
int max;
int n, m, k;
int initialized = 0;
pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;

void* threadFunc(void* arg){
  threadFunc_t* args = (threadFunc_t*)arg;
  int res = 0, i = 0;
  
  for(i = 0; i < m; i++)
    res += matA[args->row][i] * matB[i][args->col];
  
  check_errorP(pthread_mutex_lock(&globalLock), "lock failed");
  
  matC[args->row][args->col] = res;
  if(!initialized){
    max = res;
    initialized = 1;
  }
  else{
    if(max < res)
      max = res;
  }
  
  check_errorP(pthread_mutex_unlock(&globalLock), "unlock failed");
  
  return NULL;
}

int main(){
  int i, j;
  // Prva matrica
  scanf("%d%d", &n, &m);
  matA = malloc(n * sizeof(int*));
  check_error(matA != NULL, "malloc failed");  
  for(i = 0;  i < n; i++){
    matA[i] = malloc(m * sizeof(int));
    check_error(matA[i] != NULL, "malloc failed");
  }  
  for(i = 0;  i < n; i++)
    for(j = 0; j < m; j++)
      scanf("%d", &matA[i][j]);
  // Druga matrica
  scanf("%d%d", &m, &k);
  matB = malloc(m * sizeof(int*));
  check_error(matB != NULL, "malloc failed");
  for(i = 0;  i < m; i++){
    matB[i] = malloc(k * sizeof(int));
    check_error(matB[i] != NULL, "malloc failed");
  }  
  for(i = 0;  i < m; i++)
    for(j = 0; j < k; j++)
      scanf("%d", &matB[i][j]);
  // Treca matrica
  matC = malloc(n * sizeof(int*));
  check_error(matC != NULL, "malloc failed");
  for(i = 0;  i < n; i++){
    matC[i] = malloc(k * sizeof(int));
    check_error(matC[i] != NULL, "malloc failed");
  }
  
  pthread_t* tids = malloc(n * sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadFunc_t* args = malloc(n * k * sizeof(threadFunc_t));
  check_error(args != NULL, "malloc failed");
  
  for(i = 0; i < n; i++){
    for(j = 0; j < k; j++){
      args[i*k + j].row = i;
      args[i*k + j].col = j;
      check_errorP(pthread_create(&tids[i*k+j], NULL, threadFunc, &args[i*k+j]), "create failed");
    }
  }
  
  for(i = 0; i < n*k; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  check_errorP(pthread_mutex_destroy(&globalLock), "destroy failed");
  
  for(i = 0; i < n; i++){
    for(j = 0; j < k; j++)
      printf("%d ", matC[i][j]);
    printf("\n");
  }
  
  printf("%d\n", max);
  
  for(i = 0; i < m; i++)
    free(matB[i]);
  free(matB);
  for(i = 0; i < n; i++)
    free(matA[i]);
  free(matA);
  for(i = 0; i < n; i++)
    free(matC[i]);
  free(matC); 
	
  /*free(tids);
    free(args); */
  
  exit(EXIT_SUCCESS);
}
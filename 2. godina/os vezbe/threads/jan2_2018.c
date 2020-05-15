#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <math.h>

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
  
pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;
double minDistance = 0;
int initialized = 0;

typedef struct {
  double x;
  double y;
} Tacka;

typedef struct {
  int idx;
} threadData_t;

Tacka* t;
int alocirano = 32;
int zauzeto = 0;

void* threadFunc(void* arg){
  threadData_t* data = (threadData_t*)arg;
  
  double localMin = 0;
  int inic = 0;
  double xf = t[data->idx].x;
  double yf = t[data->idx].y;
  
  for(int i = 0; i < zauzeto; i++){
    if(i != data->idx){
      double x = t[i].x, y = t[i].y;
      double d = (xf-x)*(xf-x) + (yf-y)*(yf-y);
      if(inic){
	if(d < localMin)
	  localMin = d;
      }
      else{
	localMin = d;
	inic = 1;
      }
    }
  }
  
  check_errorP(pthread_mutex_lock(&globalLock), "lock failed");
  
  if(!initialized){
    minDistance = localMin;
    initialized = 1;
  }
  else {
    if(localMin < minDistance)
      minDistance = localMin;
  }
  
  check_errorP(pthread_mutex_unlock(&globalLock), "unlock failed");  
  
  return NULL;
}

int main(int argc, char** argv){
  check_error(argc == 1, "arguments");
  
  t = malloc(alocirano*sizeof(Tacka));
  check_error(t != NULL, "malloc failed");
  
  double x, y;
  
  while(fscanf(stdin, "%lf%lf", &x, &y) == 2){
    if(zauzeto == alocirano){
      alocirano *= 2;
      t = realloc(t, alocirano*sizeof(Tacka));
      check_error(t != NULL, "realloc failed");
    }
    t[zauzeto].x = x;
    t[zauzeto].y = y;
    zauzeto++;
  }
  
  pthread_t* tids = malloc(zauzeto*sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  threadData_t* args = malloc(zauzeto*sizeof(threadData_t));
  check_error(args != NULL, "malloc failed");
  
  for(int i = 0; i < zauzeto; i++){
    args[i].idx = i;
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "create failed");
  }
  
  for(int i = 0; i < zauzeto; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  printf("%lf\n", sqrt(minDistance));
  
  free(args);
  free(tids);
  free(t);
  
  exit(EXIT_SUCCESS);
}
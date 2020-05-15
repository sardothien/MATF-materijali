#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <ctype.h>

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
  
int maxC;
int numC;
int initialized;
pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
  char* fPath;
  char c;
} threadFunc_t;

typedef struct {
  char c;
  int num;
} threadOut_t;

void* threadFunc(void* arg){
  threadFunc_t* args = (threadFunc_t*)arg;
  
  char c;
  FILE *in = fopen(args->fPath, "r");
  check_error(in != NULL, "fopen failed");
  
  threadOut_t* localCount = malloc(sizeof(threadOut_t));
  check_error(localCount != NULL, "malloc failed");
  
  localCount->c = args->c;
  localCount->num = 0;
  
  while((c = fgetc(in)) != EOF){
    if(tolower(c) == args->c)
      localCount->num++;
  }
  
  fclose(in);
  
  check_errorP(pthread_mutex_lock(&globalLock), "lock failed");
  
  if(initialized){
    if(localCount->num > numC){
      numC = localCount->num;
      maxC = localCount->c;
    }
  }
  else {
    numC = localCount->num;
    maxC = localCount->c;
    initialized = 1;
  }
  
  check_errorP(pthread_mutex_unlock(&globalLock), "unlock failed");
  
  return localCount;
}

int main(int argc, char** argv){
  check_error(argc == 2, "arguments");
  
  pthread_t* tids = malloc(26*sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadFunc_t* args = malloc(26*sizeof(threadFunc_t));
  check_error(args != NULL, "malloc failed");
  
  for(int i = 0; i < 26; i++){
    args[i].c = 'a'+i;
    args[i].fPath = argv[1];
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "create failed");
  }
  
  for(int i = 0; i < 26; i++){
    threadOut_t* a = NULL;
    check_errorP(pthread_join(tids[i], (void**)&a), "join failed");
    printf("%d ", a->num);
    free(a);
  }
  
  printf("\n%c\n", maxC);
  
  free(tids);
  free(args);
  
  exit(EXIT_SUCCESS);
}
#define _XOPEN_SOURCE 700
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <string.h>

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
  
#define MAX (2048)

typedef struct{
  int idx;
}threadData_t;

const char* fPath;
int num = -1;
int stop[MAX];
int stopCount = 0;

pthread_mutex_t globalLock = PTHREAD_MUTEX_INITIALIZER;

void countStr(int fd, int idx, const char* str){
  int fsize = lseek(fd, 0, SEEK_END);
  check_error(fsize != -1, "lseek failed");
  
  int n = fsize / num;
  int start = n * idx;
  
  check_error(lseek(fd, start, SEEK_SET) != -1, "lseek failed");
  
  char* haystack = malloc(n + 1);
  check_error(haystack != NULL, "malloc failed");
  
  check_error(n == read(fd, haystack, n), "read failed");
  
  char* search = haystack, *pos = NULL;
  
  while((pos = strstr(search, str))){
    check_errorP(pthread_mutex_lock(&globalLock), "lock failed");
    
    stop[stopCount++] = pos - haystack + start;
		
    check_errorP(pthread_mutex_unlock(&globalLock), "unlock failed");

    search = pos + 1;
  }

  free(haystack);
}

void* threadFunc(void* arg){
  threadData_t* data = (threadData_t*)arg;
  
  int fd = open(fPath, O_RDONLY);
  check_error(fd != -1, "open failed");
  
  countStr(fd, data->idx, "tag");
  countStr(fd, data->idx, "taa");
  countStr(fd, data->idx, "tga");
  
  close(fd);
  
  return NULL;
}

int main(int argc, char** argv){
  check_error(argc == 3, "arguments");
  
  num = atoi(argv[1]);
  fPath = argv[2];
  
  pthread_t* tids = malloc(num*sizeof(pthread_t));
  check_error(tids != NULL, "malloc failed");
  
  threadData_t* args = malloc(num*sizeof(threadData_t));
  check_error(args != NULL, "malloc failed");
  
  for(int i = 0; i < num; i++){
    args[i].idx = i;
    check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "create failed");
  }
  
  for(int i = 0; i < num; i++)
    check_errorP(pthread_join(tids[i], NULL), "join failed");
  
  while(stopCount--)
    printf("%d ", stop[stopCount]);
  printf("\n");  
  
  free(args);
  free(tids);
  
  check_errorP(pthread_mutex_destroy(&globalLock), "destroy failed");
  
  exit(EXIT_SUCCESS);
}
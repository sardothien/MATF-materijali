#define _XOPEN_SOURCE 700
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<limits.h>
#include<errno.h>
#include<string.h>
#include<math.h>
#include <stdbool.h>

#define check_error(expr, userMsg)\
    do{\
        if(!(expr)){\
            fprintf(stderr, "%s\n", userMsg);\
            exit(EXIT_FAILURE);\
        }\
    }while(0);
    
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
    int start;
}threadData_t;

typedef struct {
    int idx;
    float sum;
}retValue;
    
int M, N, K, step;
float** mat; 
pthread_mutex_t globalLock;

void* threadFunc(void * arg){
    int start = ((threadData_t*)arg)->start;
    int idx = ((threadData_t*)arg)->idx;
    int end = start + step;
    
    retValue* retVal = malloc(sizeof(retValue));
    check_error(retVal != NULL, "malloc failed");
    
    float max;
    bool indicator = true;
    
    for(int i = start; i < end; i++){
        float sum = 0;
        for(int j = 0; j < N; j++)
            sum += (mat[i][j]*mat[i][j]);
        
        sum = sqrt(sum);
        
        if(indicator){
            indicator = false;
            max = sum;
        }
        else if(sum > max)
            max = sum;
    }
    
    retVal->sum = max;
    retVal->idx = idx;
    
    pthread_exit((void*)retVal);
}

int main(int argc, char **argv){
    check_error(argc == 1, "arguments");
    
    scanf("%d%d%d", &M, &N, &K);
    
    mat = malloc(M * sizeof(float*));
    check_error(mat != NULL, "malloc failed");
    
    for(int i = 0; i < M; i++){
        mat[i] = malloc(N * sizeof(float));
        check_error(mat[i] != NULL, "malloc failed");
    }
    
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            scanf("%f", &mat[i][j]);
        
    pthread_t* tids = malloc(K * sizeof(pthread_t));
    check_error(tids != NULL, "malloc failed");
    
    threadData_t* args = malloc(K * sizeof(threadData_t));
    check_error(args != NULL, "malloc failed");
    
    step = M/K;
    
    check_errorP(pthread_mutex_init(&globalLock, NULL), "init failed");
        
    for(int i = 0; i < K; i++){
        args[i].start = i * step;
        args[i].idx = i;
        check_errorP(pthread_create(&tids[i], NULL, threadFunc, &args[i]), "create failed");
    }
     
    float max = 0;
    int maxIdx;
    retValue* retVal;
        
    for(int i = 0; i < K; i++){
        check_errorP(pthread_join(tids[i], (void**)&retVal), "join failed");
        retValue threadMax = *((retValue*)retVal);
        
        if(threadMax.sum > max){
            max = threadMax.sum;
            maxIdx = threadMax.idx;
        }
        free(retVal);
    }
    printf("%d %f\n", maxIdx, max);
        
        
    for(int i = 0; i < M; i++)
        free(mat[i]);
    free(mat);
    
    free(tids);
    free(args);
    
    exit(EXIT_SUCCESS);
}

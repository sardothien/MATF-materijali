#define _XOPEN_SOURCE 700
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

#define check_error(expr, userMsg)\
    do{\
        if(!(expr)){\
            fprintf(stderr, "%s\n", userMsg);\
            exit(EXIT_FAILURE);\
        }\
    }while(0)
    
int main(int argc, char** argv){
    
    check_error(argc == 2, "arguments");
    
    int fd = open(argv[1], O_RDONLY);
    check_error(fd != -1, "open failed");
    
    FILE* in = fdopen(fd, "r");
    check_error(in != NULL, "fdopen failed");
    
    char* line = NULL;
    size_t lineLen;
    struct flock lock;
    
    while(getline(&line, &lineLen, in) != -1){
        lock.l_type = F_WRLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = ftell(in);
        lock.l_len = -lineLen;
        
        check_error(fcntl(fd, F_SETLK, &lock) != -1, "fcntl failed");
        
        switch(lock.l_type){
            case F_UNLCK: printf("%s", line); break;
            default: break;
        }
    }
    
    printf("\n");
    
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    check_error(fcntl(fd, F_SETLK, &lock) != -1, "fcntl 2 failed");    
    
    exit(EXIT_SUCCESS);
}

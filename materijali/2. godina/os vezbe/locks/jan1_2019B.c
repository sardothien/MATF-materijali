#define _XOPEN_SOURCE 700
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<errno.h>

#define check_error(expr, userMsg)\
    do{\
        if(!(expr)){\
            fprintf(stderr, "%s\n", userMsg);\
            exit(EXIT_FAILURE);\
        }\
    }while(0);
    
#define MAX (256)

int main(int argc, char** argv){
    check_error(argc == 2, "arguments");   
    
    int fd = open(argv[1], O_RDWR);
    check_error(fd != -1, "open failed");
    
    FILE* in = fdopen(fd, "r+");
    check_error(in != NULL, "fdopen failed");
    
    char buffer[MAX];
    
    while(!feof(in)){
        fscanf(in, "%s", buffer);
        int broj;
        if(sscanf(buffer, "%d", &broj) == 1 && broj > 999 && broj < 10000){
            struct flock lock;
            lock.l_type = F_WRLCK;
            lock.l_whence = SEEK_SET;
            lock.l_start = ftell(in);
            lock.l_len = -4;
            
            if(fcntl(fd, F_SETLK, &lock) != -1){
                check_error(fseek(in, -4, SEEK_CUR) != -1, "fseek failed");
                fprintf(in, "####"); 
            }
            else if(errno != EAGAIN)
                check_error(0, "fcntl failed");
        }  
    }

    fclose(in);
    
    exit(EXIT_SUCCESS);
}

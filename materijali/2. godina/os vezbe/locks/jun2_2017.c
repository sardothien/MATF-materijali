#define _XOPEN_SOURCE 700
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
    check_error(argc == 4, "arguments");   
    
    int fd = open(argv[1], O_RDWR);
    check_error(fd != -1, "open failed");
    
    FILE* in = fdopen(fd, "r+");
    check_error(in != NULL, "fdopen failed");
    
    char buffer[MAX];
    int brNepromenjen = 0;
    struct flock lock;
    
    while(!feof(in)){
        fscanf(in, "%s", buffer);
        
        if(!strcmp(buffer, argv[2])){
            lock.l_type = F_WRLCK;
            lock.l_whence = SEEK_SET;
            lock.l_start = ftell(in);
            lock.l_len = -strlen(buffer);
            
            if(fcntl(fd, F_SETLK, &lock) == -1){
                if(errno != EAGAIN && errno != EACCES)
                    check_error(0, "fcntl failed");
                brNepromenjen++;
            }
            else{
                check_error(fseek(in, -strlen(buffer), SEEK_CUR) != -1, "fseek failed");
                fprintf(in, "%s", argv[3]);
            }
        }
    }
    
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_start = 0;
    check_error(fcntl(fd, F_SETLK, &lock) != -1, "");
    
    printf("%d\n", brNepromenjen);
    
    fclose(in);    
    
    exit(EXIT_SUCCESS);
}

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
    
    int fd = open(argv[1], O_RDONLY);
    check_error(fd != -1, "open failed");
    
    FILE* in = fdopen(fd, "r");
    check_error(in != NULL, "fdopen failed");
    
    char buffer[MAX];
    int number, br = 0;
    
    while(!feof(in)){
        fscanf(in, "%s", buffer);
        
        if(sscanf(buffer, "%d", &number) == 1){
            struct flock lock;
            lock.l_type = F_RDLCK;
            lock.l_whence = SEEK_SET;
            lock.l_start = ftell(in);
            lock.l_len = -strlen(buffer); 
            
            int rez = fcntl(fd, F_SETLK, &lock);
            
            if(rez == -1){
                if(errno != EAGAIN && errno != EACCES)
                    check_error(0, "fcntl failed");
            }
            else
                br++;
        }       
    }
    
    fclose(in);
    
    printf("%d\n", br);
    
    exit(EXIT_SUCCESS);
}

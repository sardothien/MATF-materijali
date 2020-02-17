#define _XOPEN_SOURCE 700
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<string.h>

#define check_error(expr, userMsg)\
    do{\
        if(!(expr)){\
            fprintf(stderr, "%s\n", userMsg);\
            exit(EXIT_FAILURE);\
        }\
    }while(0);
    
#define RD_END (0)
#define WR_END (1)

int main(int argc, char **argv){
    check_error(argc == 2, "arguments");
    
    int cld2par[2];
    check_error(pipe(cld2par) != -1, "pipe failed");
    
    pid_t childPid = fork();
    check_error(childPid != -1, "fork failed");
    
    if(childPid == 0){
        close(cld2par[RD_END]);
        check_error(dup2(cld2par[WR_END], STDOUT_FILENO) != -1, "dup2 failed");
        check_error(execlp("stat", "stat", argv[1], NULL) != -1, "execlp failed");
    }
    
    close(cld2par[WR_END]);
    
    int status;
    check_error(waitpid(childPid, &status, 0) != -1, "waitpid failed");
    
    if(WIFEXITED(status)){
        if(WEXITSTATUS(status) != EXIT_SUCCESS){
            printf("nauspeh\n");
            return 0;
        }
    }
    else{
        printf("neuspeh\n");
        return 0;
    }
    
    FILE* in = fdopen(cld2par[RD_END], "r");
    check_error(in != NULL, "fdopen failed");
    
    char* line = NULL;
    size_t lineLen = 0;
    
    check_error(getline(&line, &lineLen, in) != -1, "getline failed");
    check_error(getline(&line, &lineLen, in) != -1, "getline failed");
    check_error(getline(&line, &lineLen, in) != -1, "getline failed");
    
    check_error(getline(&line, &lineLen, in) != -1, "getline failed");
    
    char* prava = strchr(line, '-');
    
    char rez[10];
    for(int i = 0; i < 10; i++)
        rez[i] = prava[i];
    
    for(int i = 0; i < 10; i++)
        printf("%c", rez[i]);
    printf("\n");
    
    fclose(in);
    free(line);
    
    exit(EXIT_SUCCESS);
}

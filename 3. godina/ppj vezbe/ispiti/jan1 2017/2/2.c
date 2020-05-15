#include<stdio.h>
#include<stdlib.h>
#include"tokeni.h"

#define ISPIS 1

int preduvid;
extern int yylex();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

void e();
void ep();
void t();
void f();
void fp();
void g();
void m();

void e(){
    if(preduvid == DATE || preduvid == ID){
#ifndef ISPIS
        printf("e -> t ep\n");
#endif
        t();
        ep();
    }
    else
        greska("Sintaksna greska kod E");
}

void ep(){
    if(preduvid == DATE || preduvid == ID){
#ifndef ISPIS
        printf("ep -> t ep\n");
#endif
        t();
        ep();
    }
    else
        greska("Sintaksna greska za EP");
}

void t(){
    if(preduvid == DATE){
#ifndef ISPIS
        printf("t -> DATE f TZ\n");
#endif
        preduvid = yylex();
        f();
        preduvid = yylex();
    }
    else if(preduvid == ID){
#ifndef ISPIS
        printf("t -> f TZ\n");
#endif
        f();
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska za T");
}

void f(){
    if(preduvid == ID){
#ifndef ISPIS
        printf("f -> ID g fp\n");
#endif
        preduvid = yylex();
        g();
        fp();
    }
    else
        greska("Sintaksna greska za F");
}

void fp(){
    if(preduvid == ZAR){
#ifndef ISPIS
        printf("fp -> ZAR ID g fp\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
        g();
        fp();
    }
    else
        greska("Sintaksna greska za FP");
}

void g(){
    if(preduvid == DOD){
#ifndef ISPIS
        printf("g -> DOD m\n");
#endif
        preduvid = yylex();
        m();
    }
    else
        greska("Sintaksna greska za G");
}

void m(){
    if(preduvid == BROJ || preduvid == CRTA){
#ifndef ISPIS
        printf("m -> BROJ CRTA BROJ CRTA BROJ\n");
#endif
    }
    else
        greska("Sintaksna greska kod M");
}


int main(){
    
    preduvid = yylex();
    
    e();
    
    if(preduvid != EOI)
        greska("Sintaksna greska!");
    
    printf("Ispravan iskaz!\n");
    
    return 0;
}

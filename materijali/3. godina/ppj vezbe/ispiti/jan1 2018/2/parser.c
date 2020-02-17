#include<stdio.h>
#include<stdlib.h>
#include"tokeni.h"

#define ISPIS

int preduvid;
extern int yylex();

void e();
void ep();
void f();
void t();
void tp();
void g();
void gp();
void m();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

void e(){
    if(preduvid == ID || preduvid == PRINT){
#ifndef ISPIS
        printf("e -> f TZ ep\n");
#endif
        f();
        preduvid = yylex();
        ep();
    }
    else
        greska("Sintaksna greska za E");
}

void ep(){
    if(preduvid == ID || preduvid == PRINT){
#ifndef ISPIS
        printf("ep -> f TZ ep\n");
#endif
        f();
        preduvid = TZ;
        ep();
    }
    else if(preduvid == EOI){
#ifndef ISPIS
        printf("ep -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska za EP");
}

void f(){
    if(preduvid == ID){
#ifndef ISPIS
        printf("f -> ID DOD t\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
        t();
    }
    else if(preduvid == PRINT){
#ifndef ISPIS
        printf("f -> PRINT OZ t ZZ\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
        t();
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska za F");
}

void t(){
    if(preduvid == UO){
#ifndef ISPIS
        printf("t -> UO g UZ\n");
#endif
        preduvid = yylex();
        g();
        preduvid = yylex();
    }
    else if(preduvid == ID){
#ifndef ISPIS
        printf("t -> ID\n");
#endif
        preduvid = yylex();
    }
    else if(preduvid == BROJ){
#ifndef ISPIS
        printf("t -> BROJ PUTA t\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
        t();
    }
    else if(preduvid == PLUS || preduvid == MINUS){
        tp();
    }
    else
        greska("Sintaksna greska za T");
}

void tp(){
    if(preduvid == PLUS){
#ifndef ISPIS
        printf("tp -> PLUS tp\n");
#endif
        preduvid = yylex();
        tp();
    }
    else if(preduvid == MINUS){
#ifndef ISPIS
        printf("tp -> MINUS tp\n");
#endif
        preduvid = yylex();
        tp();
    }
    else if(preduvid == EOI){
#ifndef ISPIS
        printf("tp -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska za TP");
}

void g(){
    if(preduvid == BROJ){
#ifndef ISPIS
        printf("g -> m gp\n");
#endif
        m();
        gp();
    }
    else if(preduvid == EOI || preduvid == UZ){
#ifndef ISPIS
        printf("g -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska za G");
}

void gp(){
    if(preduvid == ZAR){
#ifndef ISPIS
        printf("gp -> ZAR m gp\n");
#endif
        preduvid = yylex();
        m();
        gp();
    }
    else if(preduvid == EOI || preduvid == UZ){
#ifndef ISPIS
        printf("gp -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska za GP");
}

void m(){
    if(preduvid == BROJ){
#ifndef ISPIS
        printf("m -> BROJ\n");
#endif
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska za M");
}

int main(){
    
    preduvid = yylex();
    
    e();
    
    if(preduvid != EOI)
        printf("Ne\n");
    else
        printf("Da\n");
    
    return 0;
}

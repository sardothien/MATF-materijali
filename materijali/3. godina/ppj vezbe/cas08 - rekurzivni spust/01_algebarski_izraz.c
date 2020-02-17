/*
  Gramatika je:
  e -> e+t
      |t
  t -> t*f
      |f
  f => (e)
      |BROJ
  Moramo se obavezno osloboditi leve rekurzije
  pravila      skupovi izbora
  e -> te'     { BROJ , ( }
  e'-> + t e'  { + }
       |eps    { ) , EOI }
  t -> f t'    { ( , BROJ }
  t'-> * f t'  { * }
       |eps    { + , ) , EOI }
  f -> (e)     { ( }
       |BROJ   { BROJ }
  Skupove izbora smo dobili za sva pravila koja nisu epsilon
  na osnovu skupova PRVI, a za epsilon pravila na osnovu
  skupova SLEDI */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BROJ 1
#define PLUS 2
#define PUTA 3
#define LZ 4
#define DZ 5
#define EOI 0

#define ISPIS 1

int preduvid;

void e();
void ep();
void t();
void tp();
void f();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

// nas leksicki analizator
int yylex(){
    char c = getchar();
    
    switch(c){
        case '+': return PLUS;
        case '*': return PUTA;
        case '(': return LZ;
        case ')': return DZ;
        case '\n':
        case EOF:
            return EOI;
    }
    
    if(isdigit(c)){
        while(isdigit(c = getchar()));
        ungetc(c, stdin);
        return BROJ;
    }
    
    greska("Leksicka greska: nepoznata leksema!");
    return -1;
}

void e(){
    if(preduvid == BROJ || preduvid == LZ){
#ifndef ISPIS
        printf("e --> t ep\n");
#endif
        t();
        ep();
    }
    else
        greska("Sintaksna greska: Ocekivan je token BROJ ili (.");
}

void ep(){
    if(preduvid == PLUS){
#ifndef ISPIS
        printf("ep --> +t ep\n");
#endif
        preduvid = yylex();
        t();
        ep();
    }
    else if(preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
        printf("ep --> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska: Ocekivan je token + ili ) ili EOI.");
}

void t(){
    if(preduvid == LZ || preduvid == BROJ){
#ifndef ISPIS
        printf("t --> f tp\n");
#endif
        f();
        tp();
    }
    else
        greska("Sintaksna greska: Ocekivano je ( ili BROJ");    
}

void tp(){
    if(preduvid == PUTA){
#ifndef ISPIS
        printf("tp --> *f tp\n");
#endif
        f();
        tp();
    }
    else if(preduvid == PLUS || preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
        printf("tp --> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska: Neocekivani token!");
}

void f(){
    if(preduvid == LZ){
#ifndef ISPIS
        printf("f --> (e)\n");
#endif
        preduvid = yylex();
        e();
        if(preduvid == DZ)
            preduvid = yylex();
        else
            greska("Sintaksna greska: Ocekivano je ).");
    }
    else if(preduvid == BROJ){
#ifndef ISPIS
        printf("f --> BROJ\n");
#endif
        preduvid = yylex();
        return;
    }
}

int main(){
    
    preduvid = yylex();
    
    e();
    
    if(preduvid != EOI)
        greska("Sintaksna greska: Visak karaktera na ulazu!");
    
    return 0;    
}

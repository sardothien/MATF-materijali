// PARSER
// Izraz sa minusom koriscenjem komutativnosti sabiranja
/*
E -> T EP                     { (, broj }     { E.v = T.v + EP.v }
EP -> + T {print +} EP        { + }           { EP1.v = T.v + EP2.v }
    | - T {print - } EP       { - }           { EP1.v =  EP2.v - T.v }
    | eps                     { ), EOI }      { EP1.v = 0 }
T -> F TP                     { broj, ( }     { T.v = F.v * TP.v }
TP -> * F {print *} TP        { * }           { TP1.v = F.v * TP2.v }
    | eps                     { +, -, ), EOI}    { TP1.v = 1 }
F -> broj { print broj.v }    { broj }        { F.v = broj.v}
    | ( E )                   { ( }           { F.v = E.v }
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokeni.h"

// #define ISPIS 1

int preduvid;
int yyval;
extern int yylex();

int e();
int ep();
int t();
int tp();
int f();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

int e(){
    if(preduvid == BROJ || preduvid == LZ){
#ifndef ISPIS
        printf("e --> t ep\n");
#endif
        return t() + ep();
    }
    else
        greska("Sintaksna greska: Ocekivan je token BROJ ili (.");
}

int ep(){
    if(preduvid == PLUS){
#ifndef ISPIS
        printf("ep --> + t ep\n");
#endif
        preduvid = yylex();
        int rezultat = t();
        printf("+ ");
        return rezultat + ep();
    }
    else if(preduvid == MINUS){
#ifndef ISPIS
        printf("ep --> - t ep\n");
#endif
        preduvid = yylex();
        int rezultat = t();
        printf("- ");
        return ep - rezultat;
    }
    else if(preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
        printf("ep --> eps\n");
#endif
        return 0;
    }
    else
        greska("Sintaksna greska: Ocekivan je token + ili ) ili EOI.");
}

int t(){
    if(preduvid == LZ || preduvid == BROJ){
#ifndef ISPIS
        printf("t --> f tp\n");
#endif
        return f() * tp();
    }
    else
        greska("Sintaksna greska: Ocekivano je ( ili BROJ");    
}

int tp(){
    if(preduvid == PUTA){
#ifndef ISPIS
        printf("tp --> *f tp\n");
#endif
        preduvid = yylex();
        int rezultat = f();
        printf("* ");
        return rezultat * tp();
    }
    else if(preduvid == PODELJENO){
#ifndef ISPIS
        printf("tp --> / f tp\n");
#endif
        preduvid = yylex();
        int rezultat = f();
        printf("/ ");
        return tp() / rezultat;
    }    
    else if(preduvid == PLUS || preduvid == DZ || preduvid == EOI || preduvid == MINUS){
#ifndef ISPIS
        printf("tp --> eps\n");
#endif
        return 1;
    }
    else
        greska("Sintaksna greska: Neocekivani token!");
}

int f(){
    if(preduvid == LZ){
#ifndef ISPIS
        printf("f --> (e)\n");
#endif
        preduvid = yylex();
        int rezultat = e();
        if(preduvid != DZ)
            greska("Sintaksna greska: Ocekivano je ).");
        preduvid == yylex();
        return rezultat;
    }
    else {
        if(preduvid == BROJ){
#ifndef ISPIS
            printf("f --> BROJ\n");
#endif
            int rezultat = yyval;
            printf("%d ", yyval);
            preduvid = yylex();
            return rezultat;
        }
        else
            greska("Sintaksna greska: Ocekivano ( ili BROJ\n");
    }
}

// E=>T EP =>F TP EP => broj TP EP => broj EP => broj + T EP => broj + F TP EP =>
//   => broj + broj TP EP => broj + broj * F TP EP => broj + broj * broj TP EP
//   => broj + broj* broj

int main(){
    
    preduvid = yylex();
    
    int vrednost = e();
    
    if(preduvid == EOI){
        printf("\n\nRecenica odgovara jeziku zadatim gramatikom!");
        printf("Vrednost izraza je: %d\n", vrednost);    
    }
    else
        printf("Previse tokena na ulazu!\n");
    
    return 0;    
}

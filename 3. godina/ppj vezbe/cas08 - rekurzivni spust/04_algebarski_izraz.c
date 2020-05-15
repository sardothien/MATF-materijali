/* PARSER
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
  skupova SLEDI.
  
  Zadatak 3 hocemo da prosirimo tako da program ispisuje
  taj aritmeticki izraz, ali u postfiksnoj notaciji
  Npr 2+3 ispisuje 2 3 +
  Npr 2+3*4 ispisuje 2 3 4 * +
  Akcije koji dodajemo pravilima cemo pisati u okviru pravila
  jer cemo time precizirati kada se akcije izvrsavaju u samom pravilu
  pravila			        skupovi izbora
  e -> te'			        { BROJ , ( }
  e'-> +t{print(+)}e'       { + }
	   |eps			        { ) , EOI }
  t -> ft'			        { ( , BROJ }
  t'-> *f{print(*)}t'	    { * }
       |eps                 { + , ) , EOI }
  f -> (e)			        { ( }
	   |BROJ{print(BROJ.v)}	{ BROJ } */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokeni.h"

// #define ISPIS

int preduvid;
int yyval;

int e();
int ep();
int t();
int tp();
int f();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

extern int yylex();

int e(){
    if(preduvid == BROJ || preduvid == LZ){
#ifndef ISPIS
        printf("e --> t ep\n");
#endif
        return t() + ep();
    }
    else
        greska("Sintaksna greska: Ocekivan je token BROJ ili (.");
    return 0;
}

int ep(){
    if(preduvid == PLUS){
#ifndef ISPIS
        printf("ep --> +t ep\n");
#endif
        preduvid = yylex();
        int pom = t();
        printf("+ ");
        return pom + ep();
    }
    else if(preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
        printf("ep --> eps\n");
#endif
        return 0;
    }
    else
        greska("Sintaksna greska: Ocekivan je token + ili ) ili EOI.");
    return 0;
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
    return 0;
}

int tp(){
    if(preduvid == PUTA){
#ifndef ISPIS
        printf("tp --> *f tp\n");
#endif
        int pom;
        preduvid = yylex();
        pom = f();
        printf("* ");
        return pom * tp();
    }
    else if(preduvid == PLUS || preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
        printf("tp --> eps\n");
#endif
        return 1;
    }
    else
        greska("Sintaksna greska: Neocekivani token!");
    return 0;
}

int f(){
    if(preduvid == LZ){
#ifndef ISPIS
        printf("f --> (e)\n");
#endif
        int pom;
        preduvid = yylex();
        pom = e();
        if(preduvid != DZ)
            greska("Sintaksna greska: Ocekivano je ).");
        preduvid == yylex();
        return pom;
    }
    else {
        if(preduvid == BROJ){
#ifndef ISPIS
            printf("f --> BROJ\n");
#endif
            preduvid = yylex();
            printf("%d ", yyval);
            return yyval;
        }
        else
            greska("Sintaksna greska: Ocekivano ( ili BROJ\n");
    }
    return 0;
}

int main(){
    
    int rezultat;
    preduvid = yylex();
    
    rezultat = e();
    
    if(preduvid != EOI)
        greska("Sintaksna greska: Visak karaktera na ulazu!");
    
    printf("Vrednost izraza je: %d\n", rezultat);
    
    return 0;    
}

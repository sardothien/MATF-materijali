// PARSER
// Izraz sa minusom koriscenjem nasledjenih atributa
/*
e -> t ep                     { (, BROJ }     { e.v = ep.v , ep.nasledjen = t.v}
ep -> + t {print +} ep        { + }           { ep1.v = ep2.v , ep2.nasledjen = ep1.nasledjen + t.v }
    | - t {print - } ep       { - }           { ep1.v = ep2.v , ep2.nasledjen = ep1.nasledjen - t.v   
    | eps                     { ), EOI }      { ep1.v = ep1.nasledjen }
t -> f tp                     { BROJ, ( }     { t.v = tp.v }
tp -> * f {print *} tp        { * }           { tp1.v = tp2.v, tp2.nasledjen =  tp1.nasledjen  * f.v }
    | eps                     { +, -, ), EOI}    { tp1.v = tp1.nasledjen }
f -> BROJ { print BROJ.v }    { BROJ }        { f.v = BROJ.v}    
    | ( e )                   { ( }           { f.v = e.v }
    
 Nasledjen atribut se propagira od korena prema listovima stabla, a sintetizovani od listova prema korenu.   
 Nasledjene atribute prosledjujemo funkcijama preko argumenta,
 a sintetizovani funkcije vracaju preko povratnih vrednosti.
 
 Dakle kako se sintaksna analiza radi sa leva na desno tako se vrednost izraza racuna 
 i vrednost pocetnog dela izraza propagira se preko argumenta funkcijama kojima je potreban
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokeni.h"

// #define ISPIS 1

int preduvid;
int yyval;

int e();
int ep(int nasledjen);
int t();
int tp(int nasledjen);
int f();

extern int yylex();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

int e(){
    if(preduvid == BROJ || preduvid == LZ){
#ifndef ISPIS
        printf("e --> t ep\n");
#endif
        int rezultat = t();
        return ep(rezultat);
    }
    else
        greska("Sintaksna greska: Ocekivan je token BROJ ili (.");
}

int ep(int nasledjen){
    if(preduvid == PLUS){
#ifndef ISPIS
        printf("ep --> +t ep\n");
#endif
        preduvid = yylex();
        int rezultat = nasledjen + t();
        printf("+ ");
        return ep(rezultat);
    }
    else if(preduvid == MINUS){
#ifndef ISPIS
        printf("ep --> - t ep\n");
#endif
        preduvid = yylex();
        int rezultat = nasledjen - t();
        printf("- ");
        return ep(rezultat);
    }
    else if(preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
        printf("ep --> eps\n");
#endif
        return nasledjen;
    }
    else
        greska("Sintaksna greska: Ocekivan je token + ili ) ili EOI.");
}

int t(){
    if(preduvid == LZ || preduvid == BROJ){
#ifndef ISPIS
        printf("t --> f tp\n");
#endif
        int rezultat = f();
        return tp(rezultat);
    }
    else
        greska("Sintaksna greska: Ocekivano je ( ili BROJ");    
}

int tp(int nasledjen){
    if(preduvid == PUTA){
#ifndef ISPIS
        printf("tp --> *f tp\n");
#endif
        preduvid = yylex();
        int rezultat = nasledjen * f();
        printf("* ");
        return tp(rezultat);
    }
    else if(preduvid == PODELJENO){
#ifndef ISPIS
        printf("tp --> / f tp\n");
#endif
        preduvid = yylex();
        int rezultat = nasledjen / f();
        printf("/ ");
        return tp(rezultat);
    }    
    else if(preduvid == PLUS || preduvid == DZ || preduvid == EOI || preduvid == MINUS){
#ifndef ISPIS
        printf("tp --> eps\n");
#endif
        return nasledjen;
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

// e=>t ep =>f tp ep => BROJ tp ep => BROJ ep => BROJ + t ep => BROJ + f tp ep =>
//   => BROJ + BROJ tp ep => BROJ + BROJ * f tp ep => BROJ + BROJ * BROJ tp ep
//   => BROJ + BROJ* BROJ

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

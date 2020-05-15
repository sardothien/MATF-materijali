/* Gramatika: 
 *  e -> e t TZ
 *     | t TZ
 *  t -> INT ID DOD f
 *     | PRINT OZ f ZZ
 *     | f
 *  f -> f ILI g
 *     | g
 *  g -> g III h
 *     | h
 *  h -> NEG m
 *     | m
 *  m -> BROJ
 *     | ID
 *     | OZ f ZZ
 * 
 * Bez leve rekurzije:          PRVI                            SLEDI
 *  e -> t TZ ep            {INT, PRINT, NEG, BROJ, OZ, ID}
 *  ep -> t TZ ep           {INT, PRINT, NEG, BROJ, OZ, ID}
 *      | eps                                                   {EOI}
 *  t -> INT ID DOD f       {INT}
 *      | PRINT OZ f ZZ     {PRINT}
 *      | f                 {NEG, BROJ, OZ, ID}
 *  f -> g fp               {NEG, BROJ, OZ, ID}
 *  fp -> ILI g fp          {ILI}
 *      | eps                                                   {EOI, TZ, ZZ}
 *  g -> h gp               {NEG, BROJ, OZ, ID}
 *  gp -> III h gp          {III}
 *      | eps                                                   {EOI, TZ, ZZ, ILI}
 *  h -> NEG m              {NEG}
 *      | m                 {BROJ, OZ, ID}
 *  m -> BROJ               {BROJ}
 *      | ID                {ID}
 *      | OZ f ZZ           {OZ}
 */

#include<stdio.h>
#include<stdlib.h>
#include"tokeni.h"

#define ISPIS 1

int preduvid;
extern int yylex();

void e();
void ep();
void t();
void f();
void fp();
void g();
void gp();
void h();
void m();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

void e(){
    if(preduvid == INT || preduvid == PRINT || preduvid == NEG || preduvid == BROJ || preduvid == OZ || preduvid == ID){
#ifndef ISPIS
        printf("e -> t TZ ep\n");
#endif
        t();
        preduvid = yylex();
        ep();
    }
    else
        greska("Sintaksna greska kod E");
}

void ep(){
    if(preduvid == INT || preduvid == PRINT || preduvid == NEG || preduvid == BROJ || preduvid == OZ || preduvid == ID){
#ifndef ISPIS
        printf("ep -> t TZ ep\n");
#endif
        t();
        preduvid = yylex();
        ep();
    }
    else if(preduvid == EOI){
#ifndef ISPIS
        printf("ep -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska kod EP");
}

void t(){
    if(preduvid == INT){
#ifndef ISPIS
        printf("t -> INT ID DOD f\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
        preduvid = yylex();
        f();
    }
    else if(preduvid == PRINT){
#ifndef ISPIS
        printf("t -> PRINT OZ f ZZ\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
        f();
        preduvid = yylex();
    }
    else if(preduvid == NEG || preduvid == BROJ || preduvid == OZ || preduvid == ID){
#ifndef ISPIS
        printf("t -> f\n");
#endif
        f();
    }
    else
        greska("Sintaksna greska kod T");
}

void f(){
    if(preduvid == NEG || preduvid == BROJ || preduvid == OZ || preduvid == ID){
#ifndef ISPIS
        printf("f -> g fp\n");
#endif
        g();
        fp();
    }
    else
        greska("Sintaksna greska za F");
}

void fp(){
    if(preduvid == ILI){
#ifndef ISPIS
        printf("fp -> | g fp\n");
#endif
        preduvid = yylex();
        g();
        fp();
    }
    else if(preduvid == EOI || preduvid == TZ || preduvid == ZZ){
#ifndef ISPIS
        printf("fp -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska kod FP");
}

void g(){
    if(preduvid == NEG || preduvid == BROJ || preduvid == OZ || preduvid == ID){
#ifndef ISPIS
        printf("g -> h gp\n");
#endif
        h();
        gp();
    }
    else
        greska("Sintaksna greska kod G");
}

void gp(){
    if(preduvid == III){
#ifndef ISPIS
        printf("gp -> III h gp\n");
#endif
        preduvid = yylex();
        h();
        gp();
    }
    else if(preduvid == EOI || preduvid == TZ || preduvid == ILI || preduvid == ZZ){
#ifndef ISPIS
        printf("gp -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska kod GP");
}

void h(){
    if(preduvid == NEG){
#ifndef ISPIS
        printf("h -> NEG m\n");
#endif
        preduvid = yylex();
        m();
    }
    else if(preduvid == BROJ || preduvid == OZ || preduvid == ID){
#ifndef ISPIS
        printf("h -> m\n");
#endif
        m();
    }
    else
        greska("Sintaksna greska za H");
}

void m(){
    if(preduvid == BROJ){
#ifndef ISPIS
        printf("m -> BROJ");
#endif
        preduvid = yylex();
    }
    else if(preduvid == ID){
#ifndef ISPIS 
        printf("m -> ID\n");
#endif
        preduvid = yylex();
    }
    else if(preduvid == OZ){
#ifndef ISPIS
        printf("m -> OZ f ZZ\n");
#endif
        preduvid = yylex();
        f();
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska za M");
}


int main(){
    preduvid = yylex();
    
    e();
    
    if(preduvid != EOI)
        greska("Sintaksna greska!");
    
    printf("Iskaz je prepoznat.\n");
    
    return 0;
}

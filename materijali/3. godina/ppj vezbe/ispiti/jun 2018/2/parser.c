/* Gramatika:
 *  e -> e t
 *     | t
 *  t -> DISP OZ f ZZ
 *     | ID DOD f
 *  f -> UO g UZ
 *     | ID
 *  g -> g ZAR BROJ
 *     | BROJ
 * 
 *  Eliminisanje leve rekurzije:    PRVI        SLEDI
 *      e -> t ep                   {DISP, ID}
 *      ep -> t ep                  {DISP, ID}
 *          | eps                               {EOI}
 *      t -> DISP OZ f ZZ           {DISP}
 *          | ID DOD f              {ID}
 *      f -> UO g UZ                {UO}
 *          | ID                    {ID}
 *      g -> BROJ gp                {BROJ}
 *      gp -> ZAR BROJ gp           {ZAR}
 *          | eps                               {EOI, UZ}
 */

#include<stdio.h>
#include<stdlib.h>
#include"tokeni.h"

#define ISPIS

int preduvid;
extern int yylex();

void e();
void ep();
void t();
void f();
void g();
void gp();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

void e(){
    if(preduvid == DISP || preduvid == ID){
#ifndef ISPIS
        printf("e -> t ep\n");
#endif
        t();
        ep();
    }
    else
        greska("Sintaksna greska za E");
}

void ep(){
    if(preduvid == DISP || preduvid == ID){
#ifndef ISPIS
        printf("ep -> t ep\n");
#endif
        t();
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

void t(){
    if(preduvid == DISP){
#ifndef ISPIS
        printf("t -> DISP OZ f ZZ\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
        f();
        preduvid = yylex();
    }
    else if(preduvid == ID){
#ifndef ISPIS
        printf("t -> ID DOD f\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
        f();
    }
    else
        greska("Sintaksna greska za T");
}

void f(){
    if(preduvid == UO){
#ifndef ISPIS
        printf("f -> UO g UZ\n");
#endif
        preduvid = yylex();
        g();
        preduvid = yylex();
    }
    else if(preduvid == ID){
#ifndef ISPIS
        printf("f -> ID\n");
#endif
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska za F");
}

void g(){
    if(preduvid == BROJ){
#ifndef ISPIS
        printf("g -> BROJ gp\n");
#endif
        preduvid = yylex();
        gp();
    }
    else
        greska("Sintaksna greska za G");
}

void gp(){
    if(preduvid == ZAR){
#ifndef ISPIS
        printf("gp -> ZAR BROJ gp\n");
#endif
        preduvid = yylex();
        preduvid = yylex();
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

int main(){
    
    preduvid = yylex();
    
    e();
    
    if(preduvid != EOI)
        greska("Sintaksna greska!");
    
    printf("Izraz je prepoznat!\n");
    
    return 0;
}

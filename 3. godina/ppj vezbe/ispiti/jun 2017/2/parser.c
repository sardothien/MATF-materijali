/* Gramatika:
 	e -> e f
           | f
	f -> t 
	   | PRINT t TZ
	t -> t TACKA g
	   | g
	g -> OZ m ZZ
	   | OZ ZZ
	m -> m ZAR n
	   | n
	n -> BROJ

   Bez leve rekurzije:		PRVI		SLEDECI
	e -> f ep		{PRINT, OZ}
	ep -> f ep		{PRINT, OZ}
  	    | eps				{EOI}
	f -> t			{OZ}
	    | PRINT t TZ	{PRINT}
	t -> g tp		{OZ}
	tp -> TACKA g tp	{TACKA}
	    | eps				{EOI, TZ}
	g -> OZ m ZZ		{OZ}
	m -> n mp		{BROJ}
	    | eps				{EOI, ZZ}
	mp -> ZAR n mp		{ZAR}
	    | eps				{EOI, ZZ}
	n -> BROJ 		{BROJ}
 */

#include<stdio.h>
#include<stdlib.h>
#include"tokeni.h"

#define ISPIS 1

int preduvid;
extern int yylex();

void e();
void ep();
void f();
void t();
void tp();
void g();
void m();
void mp();
void n();

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

void e(){
    if(preduvid == PRINT || preduvid == OZ){
#ifndef ISPIS
        printf("e -> f ep\n");
#endif
        f();
        ep();
    }
    else
        greska("Sintaksna greska kod E");
}

void ep(){
    if(preduvid == OZ || preduvid == PRINT){
#ifndef ISPIS
        printf("ep -> f ep\n");
#endif
        f();
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

void f(){
    if(preduvid == OZ){
#ifndef ISPIS 
        printf("f -> t\n");
#endif
        t();
    }
    else if(preduvid == PRINT){
#ifndef ISPIS
        printf("f -> PRINT t TZ\n");
#endif
        preduvid =  yylex();
        t();
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska kod F");
}

void t(){
    if(preduvid == OZ){
#ifndef ISPIS
        printf("t -> g tp\n");
#endif
        g();
        tp();
    }
    else
        greska("Sintaksna greska kod T");
}

void tp(){
    if(preduvid == TACKA){
#ifndef ISPIS
        printf("tp -> TACKA g tp\n");
#endif
        preduvid = yylex();
        g();
        tp();
    }
    else if(preduvid == EOI || preduvid == TZ){
#ifndef ISPIS
        printf("tp -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska kod TP");
}

void g(){
    if(preduvid == OZ){
#ifndef ISPIS
        printf("g -> OZ m ZZ\n");
#endif
        preduvid = yylex();
        m();
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska kod G");
}

void m(){
    if(preduvid == BROJ){
#ifndef ISPIS
        printf("m -> n mp\n");
#endif
        n();
        mp();
    }
    else if(preduvid == EOI || preduvid == ZZ){
#ifndef ISPIS
        printf("m -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska kod M");
}

void mp(){
    if(preduvid == ZAR){
#ifndef ISPIS
        printf("mp -> ZAR n mp\n");
#endif
        preduvid = yylex();
        n();
        mp();
    }
    else if(preduvid == EOI || preduvid == ZZ){
#ifndef ISPIS
        printf("mp -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska kod MP");
}

void n(){
    if(preduvid == BROJ){
#ifndef ISPIS
        printf("n -> BROJ\n");
#endif
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska kod N");
}

int main(){
    
    preduvid = yylex();
    
    e();
    
    if(preduvid != EOI)
        greska("Sintaksna greska");
    
    printf("Izraz je prepoznat!\n");
    
    return 0;
}

/* Gramatika:
    e -> e /\ f
       | e \/ f
       | f
    f -> !t
       | t
    t -> (e)
       | ID
       | True
       | False
       
  Oslobadjanje leve rekurzije:
  
    e -> f ep
    ep -> /\ f ep
        | \/ f ep
        | eps
    f -> !t
        | t
    t -> (e)
        | ID
        | True
        | False
        
  Skupovi PRVI                 SLEDI             
    e: ! ( ID True False        ) EOI            
    ep: /\ \/                   ) EOI
    f: ! ( ID True False        /\ \/ ) EOI
    t: ( ID True False          /\ \/ ) EOI
*/
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
void f();
void t();

void e(){
    if(preduvid == NEG || preduvid == OZ || preduvid == ID || preduvid == TRUE_ID || preduvid == FALSE_ID){
#ifndef ISPIS
        printf("e -> f ep\n");
#endif
        f();
        ep();
    }
    else
        greska("Sintaksna greska kod e().");
}

void ep(){
    if(preduvid == KONJ){
#ifndef ISPIS
        printf("ep -> /\ f ep\n");
#endif
        preduvid = yylex();
        f();
        ep();
    }
    else if(preduvid == DISJ){
#ifndef ISPIS
        printf("ep -> \/ f ep\n");
#endif
        preduvid = yylex();
        f();
        ep();
    }
    else if(preduvid == EOI || preduvid == OZ){
#ifndef ISPIS
        printf("ep -> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska kod ep().");
}

void f(){
    if(preduvid == NEG){
#ifndef ISPIS
        printf("f -> ! t\n");
#endif
        preduvid = yylex();
        t();
    }
    else if(preduvid == OZ || preduvid == ID || preduvid == TRUE_ID || preduvid == FALSE_ID){
#ifndef ISPIS
        printf("f -> t\n");
#endif
        t();
    }
    else
        greska("Sintaksna greska kod f().");
}

void t(){
    if(preduvid == OZ){
#ifndef ISPIS
        printf("t -> (e)\n");
#endif
        preduvid = yylex();
        e();
        if(preduvid == ZZ)  
            preduvid = yylex();
        else
            greska("Ocekivana ZZ kod t().");
    }
    else if(preduvid == ID){
#ifndef ISPIS
        printf("t -> ID\n");
#endif
        preduvid = yylex();
    }
    else if(preduvid == TRUE_ID){
#ifndef ISPIS
        printf("t -> True\n");
#endif
        preduvid = yylex();
    }
    else if(preduvid == FALSE_ID){
#ifndef ISPIS
        printf("t -> False\n");
#endif
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska kod t().");
}

int main(){
    preduvid = yylex();
    
    e();
    
    if(preduvid != EOI)
        greska("Sintaksna greska!");
    
    printf("Ispravan iskaz!\n");
    
    return 0;
}

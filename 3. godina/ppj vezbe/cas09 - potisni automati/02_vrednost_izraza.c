/*******************************
*  Gramatika je:
*  E -> E+T
*      |T
*  T -> T*F
*      |F
*  F => (E)
*      |num
*  Moramo se obavezno osloboditi leve rekurzije.
* 
*  pravilo        skup izbora
*  E -> TE'       { broj , ( }
*  E'-> +TE'      { + }
*       |eps      { ) , EOI }
*  T -> FT'       { ( , broj }
*  T'-> *FT'      { * }
*       |eps      { + , ) , EOI }
*  F -> (E)       { ( }
*       |num      { broj }
* 
* Uradicemo sintaksnu analizu odozgo nadole, simulacijom rada potisnog automata.
* 
* Za racunanje vrednosti, izraz se prevodi u postfiksnu notaicju, a potom se putem
* steka vrednosti racuna vrednost izraza. 
* Prevodjenje u postfiksnu notaciju se postize sledecom shemom.
* (u ovom slucaju se koristi leva asocijativnost) 
* 
*  E -> TE'			
*  E'-> +T {print(+)} E'		
*      |eps			
*  T -> FT'			
*  T'-> *F {print(*)} T'	
*      |eps			
*  F -> (E)		
*      |num {print(num.v)}	
* 
* Akcija u sredini pravila mozemo se osloboditi uvodjenjem pomocnih neterminala, 
* kao sto je opisano u sledecoj shemi.
* 
*  E -> TE'			
*  E'-> +T A1 E'		
*      |eps			
*  T -> FT'			
*  T'-> *F A2 T'		
*      |eps		
*  F -> (E)		
*      |num   { print(num.v) }
*  A1-> eps   { print(+) }
*  A2->eps    { print(*) }
* 
* Ukoliko zelimo i efektivno da se izracunava vrednost uvodi se pored steka za 
* parsiranje u stek vrednost i akcije menjaju.
* 
*  E -> TE'			
*  E'-> +T A1 E'		
*      |eps			
*  T -> FT'			
*  T'-> *F A2 T'		
*      |eps		
*  F -> (E)		
*      |num   { push(num.v) }
*  A1-> eps   { a=pop(); b=pop(); push(a+b) }
*  A2->eps    {a=pop(); b=pop(); push(a*b)  }
* 
* Oslanjanjem na stek vrednosti i uvedene pomocne neterminale
* mozemo uvesti i operatore - i / i uprkos tome sto koristimo 
* desno rekurzivnu gramatiku racunamo ispravne vrednosti izraza
* u kojima ucestvuju i ovi levo rekurzivni operatori. 
*******************************/

#include <stdio.h>
#include <stdlib.h>
#include "tokeni.h"

#define MAX 256
// #define ISPIS 1

extern int yylex();

void greska(char *s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

int preduvid;
int yyval;

#define STACK(type, array) type array[MAX];\
    int sp_##array = 0;
    
#define empty(array) (sp_##array <= 0)
#define full(array) (sp_##array >= MAX)
#define top(array) (empty(array) ? greska("Top(): prazan stek"),1 : (array[sp_##array-1])) 
#define pop(array) (empty(array) ? greska("Pop(): prazan stek"),1 : (array[--sp_##array]))
#define push(array, x) (full(array) ? greska("Push(): pun stek"),1 : (array[sp_##array++] = (x)))

int main(){
    
    STACK(int, parse_stack);
    STACK(int, value_stack);
    preduvid = yylex();
    
    push(parse_stack, E);
    
    while(!empty(parse_stack)){
        switch(top(parse_stack)){
            case E:
                if(preduvid == BROJ || preduvid == LZ){
#ifndef ISPIS
                    printf("E --> T EP\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, EP);
                    push(parse_stack, T);
                }
                else 
                    greska("Sintaksna greska za E.");
                break;
            case EP:
                if(preduvid == PLUS){
#ifndef ISPIS
                    printf("EP --> + T A1 EP\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, EP);
                    push(parse_stack, A1);
                    push(parse_stack, T);
                    push(parse_stack, PLUS);
                }
                else if(preduvid == MINUS){
#ifndef ISPIS
                    printf("EP --> - T A3 EP\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, EP);
                    push(parse_stack, A3);
                    push(parse_stack, T);
                    push(parse_stack, MINUS);
                }
                else if(preduvid == EOI || preduvid == DZ){
#ifndef ISPIS
                    printf("EP --> eps\n");
#endif
                    pop(parse_stack);
                }
                else
                    greska("Sintaksna greska za EP.");
                break;
            case T:
                if(preduvid == BROJ || preduvid == LZ){
#ifndef ISPIS
                    printf("T --> F TP\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, TP);
                    push(parse_stack, F);
                }
                else
                    greska("Sintaksna greska za T.");
                break;
            case TP:
                if(preduvid == PUTA){
#ifndef ISPIS
                    printf("TP --> * F A2 TP\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, TP);
                    push(parse_stack, A2);
                    push(parse_stack, F);
                    push(parse_stack, PUTA);
                }
                else if(preduvid == PLUS || preduvid == MINUS || preduvid == DZ || preduvid == EOI){
#ifndef ISPIS
                    printf("TP --> eps\n");
#endif
                    pop(parse_stack);
                }
                else
                    greska("Sintaksna greska za TP.");
                break;
            case F:
                if(preduvid == BROJ){
#ifndef ISPIS
                    printf("F --> broj\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, BROJ);
                    printf("%d ", yyval);
                    push(value_stack, yyval);
                }
                else if(preduvid == LZ){
#ifndef ISPIS
                    printf("F --> ( E )\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, DZ);
                    push(parse_stack, E);
                    push(parse_stack, LZ);
                }
                else
                    greska("Sintaksna greska za F.");
                break;
            case A1: 
                {
                    int a, b;
                    pop(parse_stack);                    
#ifndef ISPIS
                    printf("A1 --> eps");
                    printf("+ ");
#endif                    
                    b = pop(value_stack);
                    a = pop(value_stack);
                    push(value_stack, a+b);
                    break;
                }
            case A2:
                {
                    int a,b;
                    pop(parse_stack);
#ifndef ISPIS
                    printf("A2 -> eps");
                    printf("* ");
#endif
                    b = pop(value_stack);
                    a = pop(value_stack);
                    push(value_stack,a*b);
                    break;
                }
            case A3:
                {
                    int a,b;
                    pop(parse_stack);
#ifndef ISPIS
                    printf("A3 -> eps");
                    printf("- ");
#endif
                    b = pop(value_stack);
                    a = pop(value_stack);
                    push(value_stack,a-b);
                    break;
                }
            default:
                if(top(parse_stack) == preduvid){
					pop(parse_stack);
					preduvid = yylex();
				}
				else 
                    switch(top(parse_stack)){
                        case PUTA: greska("Sintaksna greska: ocekivano je *");
                        case PLUS: greska("Sintaksna greska: ocekivano je +");
                        case BROJ: greska("Sintaksna greska: ocekivano je BROJ");
                        case LZ: greska("Sintaksna greska: ocekivano je (");
                        case DZ: greska("Sintaksna greska: ocekivano je )");		
                    }
        }
    }
    
    if(preduvid != EOI)
        greska("Sintaksna greska: previse tokena na ulazu!");
    
    printf("Vrednost izraza je: %d\n", top(value_stack));
    
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include"tokeni.h"

#define ISPIS
#define MAX 256

extern int yylex();
int preduvid;

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

#define STACK(type, array) type array[MAX];\
    int sp_##array = 0;
    
#define empty(array) (sp_##array <= 0)
#define full(array) (sp_##array >= MAX)
#define top(array) (empty(array) ? greska("Top(): prazan stek"),1 : (array[sp_##array-1]))
#define pop(array) (empty(array) ? greska("Pop(): prazan stek"),1 : (array[--sp_##array]))
#define push(array, x) (full(array) ? greska("Push(): pun stek"),1 : (array[sp_##array++] = (x)))    
    
int main(){
    
    STACK(int, parse_stack);
    preduvid = yylex();
    
    push(parse_stack, E);
    
    while(!empty(parse_stack)){
        switch(top(parse_stack)){
            case E:
                if(preduvid == NEG || preduvid == TRUE || preduvid == FALSE || preduvid == UNDEF){
#ifndef ISPIS
                    printf("e -> t ep\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, EP);
                    push(parse_stack, T);
                }
                else if(preduvid == ID){
#ifndef ISPIS
                    printf("e -> ID DOD E\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, E);
                    push(parse_stack, DOD);
                    push(parse_stack, ID);
                }
                else
                    greska("Sintaksna greska kod E");
                break;
            case EP:
                if(preduvid == DISJ){
#ifndef ISPIS
                    printf("ep -> DISJ t ep\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, EP);
                    push(parse_stack, T);
                    push(parse_stack, DISJ);
                }
                else if(preduvid == EOI){
#ifndef ISPIS
                    printf("ep -> eps\n");
#endif
                    pop(parse_stack);
                }
                else
                    greska("Sintaksna greska kod EP");
                break;
            case T: 
                if(preduvid == NEG || preduvid == TRUE || preduvid == FALSE || preduvid == UNDEF || preduvid == ID){
#ifndef ISPIS
                    printf("t -> f tp\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, TP);
                    push(parse_stack, F);
                }
                else
                    greska("Sintaksna greska kod T");
                break;
            case TP:
                if(preduvid == KONJ){
#ifndef ISPIS
                    printf("tp -> KONJ f tp\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, TP);
                    push(parse_stack, F);
                    push(parse_stack, KONJ);
                }
                else if(preduvid == EOI){
#ifndef ISPIS
                    printf("tp -> eps");
#endif
                    pop(parse_stack);
                }
                else
                    greska("Sintaksna greska kod TP");
                break;
            case F:
                if(preduvid == ID){
#ifndef ISPIS
                    printf("f -> ID\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, ID);
                }
                else if(preduvid == NEG){
#ifndef ISPIS
                    printf("f -> NEG e\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, E);
                    push(parse_stack, NEG);
                }
                else if(preduvid == TRUE){
#ifndef ISPIS
                    printf("f -> TRUE\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, TRUE);
                }
                else if(preduvid == FALSE){
#ifndef ISPIS
                    printf("f -> FALSE\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, FALSE);
                }
                else if(preduvid == UNDEF){
#ifndef ISPIS
                    printf("f -> UNDEF\n");
#endif
                    pop(parse_stack);
                    push(parse_stack, UNDEF);
                }
                else
                    greska("Sintaksna greska kod F");
                break;
            default:
                if(top(parse_stack) == preduvid){
                    pop(parse_stack);
                    preduvid = yylex();
                }
                else{
                    greska("Sintaksna greska!!!");
                }
        }
    }
    
    if(preduvid != EOI)
        greska("Rezultat nije dobar!");
    
    printf("Iskaz je prepoznat\n");
    
    return 0;
}

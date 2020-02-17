 /*
   * niznaredbi -> naredba TZ niznaredbi
   * 		       | naredba
   * 
   * oslobadjamo se leve faktorizacije
   * 
niznaredbi -> naredba nizp  	{WHILE,IF,ID,BEGIN,TZ,EOI, END}
nizp -> TZ niznaredbi		    {TZ}
        | eps 			        {EOI, END}

naredba -> ID DOD izraz				                {ID}
          | WHILE (izraz ROP izraz ) DO naredba		{WHILE}
          | IF ( izraz ROP izraz ) THEN naredba		{IF}
          | BEGIN niznaredbi END			        {BEGIN}
          | eps						                {EOI, END,TZ}

izraz -> ID   		{ID}
      | BROJ	 	{BROJ}
 
 
Anulirajuci
	        Anulirajuci         Prvi   			    Sledi
niznaredbi     eps   	{WHILE,IF,ID,BEGIN,TZ}	  {EOI, END}
nizp           eps	    {TZ}				      {EOI, END}
naredba        eps	    {WHILE,IF,ID,BEGIN}		  {EOI, END,TZ}
izraz	        /		{ID, BROJ}			      {ROP,),TZ,EOI, END} 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "tokeni.h"

#define MAX 256
#define ISPIS 1

void greska(char* s){
    fprintf(stderr, "%s\n", s);
    exit(EXIT_FAILURE);
}

int stek[MAX];
int sp = 0;

int empty(){
    return sp <= 0;
}

int full(){
    return sp >= MAX;
}

int top(){
    if(!empty())
        return stek[sp-1];
    else 
        greska("Top(): prazan je stek!");
    return 1;
}

int pop(){
    if(!empty())
        return stek[--sp];
    else
        greska("Pop(): prazan je stek!");
    return 1;
}

void push(int x){
    if(!full()){
        stek[sp++] = x;
    }
    else
        greska("Push(): pun je stek!");
}

extern int yylex();

int main(){
    
    int preduvid = yylex();
    
    push(NIZ);
    
    while(!empty()){
        switch(top()){
            case NIZ:
                if(preduvid == WHILE_TOKEN || preduvid == IF_TOKEN || preduvid == ID
                 || preduvid == BEGIN_TOKEN || preduvid == TZ || preduvid == EOI 
                 || preduvid == END_TOKEN){
#ifdef ISPIS
                    printf("niznaredbi --> naredba nizp\n");
#endif
                    pop();
                    push(NIZP);
                    push(NAREDBA);
                }
                else
                    greska("Sintaskna greska za NIZ");
                break;
            case NIZP:
                if(preduvid == TZ){
#ifdef ISPIS
                    printf("nizp --> TZ niznaredbi\n");
#endif
                    pop();
                    push(NIZ);
                    push(TZ);
                }
                else if(preduvid == EOI || preduvid == END_TOKEN){
#ifdef ISPIS
                    printf("nizp --> eps\n");
#endif
                    pop();                
                }
                else
                    greska("Sintaskna greska za NIZP");
                break;
            case NAREDBA:
                if(preduvid == ID){
#ifdef ISPIS
                    printf("naredba --> ID DOD izraz\n");
#endif
                    pop();
                    push(IZRAZ);
                    push(DOD);
                    push(ID);
                }
                else if(preduvid == WHILE_TOKEN){
#ifdef ISPIS
                    printf("naredba --> WHILE (izraz ROP izraz) DO naredba\n");
#endif
                    pop();
                    push(NAREDBA);
                    push(DO);
                    push(DZ);
                    push(IZRAZ);
                    push(ROP);
                    push(IZRAZ);
                    push(LZ);
                    push(WHILE_TOKEN);
                }
                else if(preduvid == IF_TOKEN){
#ifdef ISPIS
                    printf("naredba --> IF (izraz ROP izraz) THEN naredba\n");
#endif
                    pop();
                    push(NAREDBA);
                    push(THEN);
                    push(DZ);
                    push(IZRAZ);
                    push(ROP);
                    push(IZRAZ);
                    push(LZ);
                    push(IF_TOKEN);
                }
                else if(preduvid == BEGIN_TOKEN){
#ifdef ISPIS
                    printf("naredba --> BEGIN niznaredbi END\n");
#endif
                    pop();
                    push(END_TOKEN);
                    push(NIZ);
                    push(BEGIN_TOKEN);
                }
                else if(preduvid == EOI || preduvid == END_TOKEN || preduvid == TZ){
#ifdef ISPIS
                    printf("naredba --> eps\n");
#endif
                    pop();
                }
                else
                    greska("Sintaskna greska za NAREDBA");
                break;
            case IZRAZ:
                if(preduvid == ID){
#ifdef ISPIS
                    printf("izraz --> ID\n");
#endif
                    pop();
                    push(ID);
                }
                else if(preduvid == BROJ){
#ifdef ISPIS
                    printf("izraz --> BROJ\n");
#endif
                    pop();
                    push(BROJ);
                }
                else
                    greska("Sintaskna greska za IZRAZ");
                break;
            default:
                if(top() == preduvid){
                    preduvid == yylex();
                    pop();
                }
                else
                    greska("Vrh steka se ne poklapa sa preduvidom!");
                break;
        }
    }
    
    if(preduvid == EOI)
        printf("Ispravan fragment koda u Paskalu\n");
    else
        printf("Visak tokena na ulazu!\n");
    
    return 0;
}

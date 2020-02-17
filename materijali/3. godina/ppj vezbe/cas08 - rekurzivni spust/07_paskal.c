/*
* Gramatika kojom je obuhvacen deo sintakse 
* programskog jezika Paskal, ilustrovan primerom
*
* naredba --> WHILE uslov DO naredba
*			| IF uslov THEN naredba
*			| ID := izraz
*			| BEGIN niznaredbi END
*			| eps	
*
* uslov --> LZ izraz ROP izraz DZ
* izraz --> ID
*			| BROJ
* niznaredbi --> niznaredbi TZ naredba	
*			| naredba
*
* Moramo da se oslobodimo leve rekurzije iz poslednjeg pravila gramatike
* Neka je aksioma gramatike neterminal niznaredbi!
*
* naredba --> WHILE uslov DO naredba
*			| IF uslov THEN naredba
*			| ID DTJ izraz
*			| BEGIN niznaredbi END
*			| eps	
*
* uslov --> LZ izraz ROP izraz RZ
* izraz --> ID
*			| BROJ
*
* niznaredbi --> naredba nizp 
* nizp --> TZ naredba nizp	
*			| eps
*
* Skupovi Prvi i Sledi 
*			Prvi				Sledi
* niznaredbi     | eps |{WHILE,IF,ID,BEGIN,TZ}          | {EOI,END}
* nizp		 | eps |{TZ}				| {EOI,END}
* naredba	 | eps |{WHILE,IF,ID,BEGIN}	        | {TZ,EOI,END}
* uslov		 |  /  |{LZ}				| {THEN,DO}
* izraz		 |  /  |{ID, BROJ}			| {ROP,RZ,TZ,EOI,END}
*
* Odredjujemo skupove izbora
* niznaredbi --> naredba nizp			{WHILE,IF,ID,BEGIN,TZ,EOI,END}  jer je niznaredbi anulirajuci simbol
* nizp --> TZ naredba nizp 				{TZ}
*		| eps							{EOI,END}
* naredba --> WHILE uslov DO naredba 	{WHILE}
*		| IF uslov THEN naredba			{IF}
*		| ID DTJ izraz					{ID}
*		| BEGIN niznaredbi END			{BEGIN}
*		| eps							{TZ,EOI,END}
* uslov --> LZ izraz ROP izraz DZ		{LZ}
* izraz --> ID							{ID}
* 		| BROJ							{BROJ}
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "tokeni.h"

#define ISPIS

int preduvid;
extern int yylex();

void niznaredbi();
void naredba();
void nizp();
void uslov();
void izraz();

void greska(char* s){
	fprintf(stderr, "%s\n", s);
	exit(EXIT_FAILURE);
}

void niznaredbi(){
    if(preduvid == WHILE_TOKEN || preduvid == IF_TOKEN || preduvid == ID || preduvid == BEGIN_TOKEN
        || preduvid == TZ || preduvid == EOI || preduvid == END_TOKEN){
#ifndef ISPIS
        printf("niznaredbi --> naredba nizp\n");
#endif
        naredba();
        nizp();
    }
    else
        greska("Sintaksna greska: ocekivano je nesto od: WHILE, IF, ID, TZ, EOI, END");
}

void naredba(){
    if(preduvid == WHILE_TOKEN){
#ifndef ISPIS
        printf("naredba --> WHILE uslov DO naredba\n");
#endif
        preduvid = yylex();
        uslov();
        if(preduvid != DO_TOKEN)
            greska("Sintaksna greska: ocekivano DO");
        preduvid = yylex();
        naredba();
    }
    else if(preduvid == IF_TOKEN){
#ifndef ISPIS
        printf("naredba --> IF uslov THEN naredba\n");
#endif
        preduvid = yylex();
        uslov();
        if(preduvid != THEN_TOKEN)
            greska("Sintaksna greska: ocekivano THEN");
        preduvid = yylex();
        naredba();
    }
    else if(preduvid == ID){
#ifndef ISPIS
        printf("naredba --> ID DTJ izraz\n");
#endif
        preduvid = yylex();
        if(preduvid != DTJ)
            greska("Sintaksna greska: ocekivano :=");
        preduvid = yylex();
        izraz();
    }
    else if(preduvid == BEGIN_TOKEN){
#ifndef ISPIS
        printf("naredba --> BEGIN niznaredbi END\n");
#endif
        preduvid = yylex();
        niznaredbi();
        if(preduvid != END_TOKEN)
            greska("Sintaksna greska: ocekivano END");
        preduvid = yylex();
    }
    else if(preduvid == TZ || preduvid == EOI || preduvid == END_TOKEN){
#ifndef ISPIS
        printf("naredba --> eps\n");
#endif
        return;
    }
    else{
        char pom[30];
        sprintf(pom, "Sintaksna greska! Neocekivani token %d!", preduvid);
        greska(pom);
    }
}

void nizp(){
    if(preduvid == TZ){
#ifndef ISPIS
        printf("nizp --> TZ naredba nizp\n");
#endif
        preduvid = yylex();
        naredba();
        nizp();
    }
    else if(preduvid == EOI || preduvid == END_TOKEN){
#ifndef ISPIS
        printf("nizp --> eps\n");
#endif
        return;
    }
    else
        greska("Sintaksna greska: ocekivano TZ ili EOI ili END");
}

void uslov(){
    if(preduvid == LZ){
#ifndef ISPIS
        printf("uslov --> LZ izraz ROP izraz DZ\n");
#endif
        preduvid = yylex();
        izraz();
        if(preduvid != ROP)
            greska("Sintaksna greska: ocekivano ROP");
        preduvid = yylex();
        izraz();
        if(preduvid != DZ)
            greska("Sintaksna greska: ocekivano DZ");
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska: ocekivano LZ");
}

void izraz(){
    if(preduvid == ID){
#ifndef ISPIS
        printf("izraz --> ID\n");
#endif
        preduvid = yylex();
    }
    else if(preduvid == BROJ){
#ifndef ISPIS
        printf("izraz --> BROJ\n");
#endif
        preduvid = yylex();
    }
    else
        greska("Sintaksna greska: ocekivano ID ili BROJ");
}

int main(){
    
    preduvid = yylex();
    niznaredbi();
    
    if(preduvid != EOI)
        greska("Visak tokena na ulazu!");
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "6.h"

#define MAX_BROJ 15
 
void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}
 
Cvor* ucitaj(FILE* f){
 char tmp[MAX_BROJ];
 if(fscanf(f, "%s", tmp) == EOF)
  return NULL;
		
 Cvor* novi = malloc(sizeof(Cvor));
 if(tmp[0] == '+' || tmp[0] == '-' || tmp[0] == '*' || tmp[0] == '/'){
  if(tmp[1] != '\0')
   greska();
  novi->operator = tmp[0];
  novi->tip = OPERACIJA;
  novi->levo = ucitaj(f);
  novi->desno = ucitaj(f);
 }
 else{
  int broj = atoi(tmp);
  novi->vrednost = broj;
  novi->tip = BROJ;
  novi->levo = NULL;
  novi->desno = NULL;
 }
 
 return novi;
}
 
void ispisi(Cvor* koren){
 if(koren == NULL)
  return;
 		
 if(koren->tip == BROJ)
  printf("%d", koren->vrednost);
 else{
  printf("(");
  ispisi(koren->levo);
  printf(")%c(", koren->operator);
  ispisi(koren->desno);
  printf(")");
 }
}
 
void oslobodi(Cvor* koren){
 if(koren){
  oslobodi(koren->levo);
  oslobodi(koren->desno);
  free(koren);
 }
}
 
float vrednost(Cvor* koren){
 if(koren == NULL)
  return 0;
 
 if(koren->tip == BROJ)
  return koren->vrednost;

 float levo = vrednost(koren->levo);
 float desno = vrednost(koren->desno);
	
 switch(koren->operator){
  case '+': return levo + desno;
	    break;
  case '-': return levo - desno;
	    break;
  case '*': return levo * desno;
	    break;
  case '/': if(desno != 0)
	     return levo/desno;
	    else
	     greska();
  default: greska();
 }
} 

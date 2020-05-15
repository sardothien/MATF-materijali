#include <stdio.h>
#include <stdlib.h>
#include "7.h"
 
void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}
 
cvor* napravi_cvor(char c){
 cvor* novi = malloc(sizeof(cvor));
 if(novi == NULL)
  greska();
		
 novi->slovo = c;
 novi->br = 1;
 novi->levo = NULL;
 novi->desno = NULL;
	
 return novi;
}
 
void dodaj_u_stablo(cvor **adresa_stabla, char c){
 if(*adresa_stabla == NULL){
  *adresa_stabla = napravi_cvor(c);
  return;
 }
	
 if(c < (*adresa_stabla)->slovo)
  dodaj_u_stablo(&(*adresa_stabla)->levo, c);
 else if(c > (*adresa_stabla)->slovo)
  dodaj_u_stablo(&(*adresa_stabla)->desno, c);
 else	
  (*adresa_stabla)->br++;
}
 
cvor* napravi_stablo_iz_fajla(FILE* f){
 cvor* s = NULL;
 char c;
 	
 while((c = fgetc(f)) != EOF)
  dodaj_u_stablo(&s, c);
 		
 return s;
}
 
cvor *maks_ponavljanja(cvor* koren){
 if(koren == NULL)
  return NULL;
 		
 cvor *maks_levo = maks_ponavljanja(koren->levo);
 cvor *maks_desno = maks_ponavljanja(koren->desno);
	
 if(maks_levo == NULL && maks_desno == NULL)
  return koren;
 
 cvor* maks_levo_desno;
 if(maks_levo == NULL)
   maks_levo_desno = maks_desno;
 else if(maks_desno == NULL)
   maks_levo_desno = maks_levo;
 else
   maks_levo_desno = maks_levo->br > maks_desno->br
                   ? maks_levo : maks_desno;
		
 return maks_levo_desno->br > koren->br ? maks_levo_desno : koren;
}
 
void oslobodi(cvor* koren){
 if(koren){
  oslobodi(koren->levo);
  oslobodi(koren->desno);
  free(koren);
 }
}

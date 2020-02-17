#include <stdio.h>
#include <stdlib.h>
#include "2.h"

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

cvor *napravi_novi(int x){
 cvor *novi = malloc(sizeof(cvor));
 if(novi == NULL)
  greska();
 
 novi->br = x;
 novi->levo = NULL;
 novi->desno = NULL;
 return novi;
}

void dodaj_u_stablo(cvor **adresa_stabla, int x){
 if(*adresa_stabla == NULL){
  cvor *novi = napravi_novi(x);
  *adresa_stabla = novi;
  return;
 }
 
 if((*adresa_stabla)->br > x) 
  dodaj_u_stablo(&((*adresa_stabla)->levo), x);
 else 
  dodaj_u_stablo(&((*adresa_stabla)->desno), x);
}

void ucitaj_stablo(cvor **adresa_stabla, FILE *f){
 int x;
 while(fscanf(f, "%d", &x) != EOF){
  dodaj_u_stablo(adresa_stabla, x);
 }
}

void oslobodi(cvor *stablo){
 if(stablo == NULL)
  return;
 
 oslobodi(stablo->levo);
 oslobodi(stablo->desno);
 free(stablo);
}

// DRUGI ZADATAK
int jednaki(cvor *koren1, cvor *koren2){
 if(koren1 == NULL && koren2 == NULL)
  return 1;
 
 // sigurno oba nisu NULL ako dodjemo do ovde
 if(koren1 == NULL)
  return 0;
 if(koren2 == NULL)
  return 0;
 
 // stabla su neprazna
 if(koren1->br == koren2->br)
  return jednaki(koren1->levo, koren2->levo) && jednaki(koren1->desno, koren2->desno);
    // umesto && moze i *
 else
  return 0; 
}

#include <stdio.h>
#include <stdlib.h>
#include "5.h"

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

int broj_jednakih_zbiru_suseda(cvor *koren, cvor *predak){
 if(koren == NULL)
  return 0;
 
 int zbir = 0;
 if(predak != NULL)
  zbir += predak->br;
 if(koren->levo != NULL)
  zbir += koren->levo->br; 
 if(koren->desno != NULL)
  zbir += koren->desno->br;
  
 int levo = broj_jednakih_zbiru_suseda(koren->levo, koren);
 int desno = broj_jednakih_zbiru_suseda(koren->desno, koren);

  
 if(koren->br == zbir)
  return 1 + levo + desno;
 else
  return levo + desno; 
}

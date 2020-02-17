#include <stdio.h>
#include <stdlib.h>
#include "1.h"

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

void ispis_infiksno(cvor *koren){
 if(koren == NULL)
  return;
 
 ispis_infiksno(koren->levo);
 printf("%d ", koren->br);
 ispis_infiksno(koren->desno);
}

void oslobodi(cvor *stablo){
 if(stablo == NULL)
  return;
 
 oslobodi(stablo->levo);
 oslobodi(stablo->desno);
 free(stablo);
}

// POD a)

cvor *pretrazi_stablo(cvor *koren, int br){
 if(koren == NULL)
  return NULL;

 if(koren->br == br)
  return koren;
 
 if(br < koren->br)
  return pretrazi_stablo(koren->levo, br);
 else
  return pretrazi_stablo(koren->desno, br);
}

// POD b)
cvor *najmanji_broj(cvor *koren){
 if(koren == NULL)
  return NULL;
 
 if(koren->levo == NULL)
  return koren;
 else
  return najmanji_broj(koren->levo);
}

// POD c)
cvor *najveci_broj(cvor *koren){
 if(koren == NULL)
  return NULL;
 
 if(koren->desno == NULL)
  return koren;
 else
  return najveci_broj(koren->desno);
}

// POD d)
void obrisi_cvor(cvor **adresa_stabla, int br){
 if(*adresa_stabla == NULL)
  return;
 
 if((*adresa_stabla)->br == br){
 
   if((*adresa_stabla)->levo == NULL){
    cvor *koren = *adresa_stabla;
    *adresa_stabla = (*adresa_stabla)->desno;
    free(koren);
    obrisi_cvor(adresa_stabla, br);
    return;
   }
   if((*adresa_stabla)->desno == NULL){
    cvor *koren = *adresa_stabla;
    *adresa_stabla = (*adresa_stabla)->levo;
    free(koren);
    obrisi_cvor(adresa_stabla, br);
    return;
   }
  
  // koren ima oba podstabla ako dodjemo do ovde
  // trazimo najveci u levom delu i menjamo vrednosti
  cvor *najveci_levo = najveci_broj((*adresa_stabla)->levo);
  (*adresa_stabla)->br = najveci_levo->br;
  najveci_levo->br = br;
 
  obrisi_cvor(&((*adresa_stabla)->levo), br);
  obrisi_cvor(&((*adresa_stabla)->desno), br);
  return;
 }
  
 if(br < (*adresa_stabla)->br){
  obrisi_cvor(&((*adresa_stabla)->levo), br);
  return;
 }
 else{
  obrisi_cvor(&((*adresa_stabla)->desno), br);
  return;
 }
}

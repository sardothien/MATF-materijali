#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

cvor *napravi_novi(int br){
 cvor *novi = malloc(sizeof(cvor));
 if(novi == NULL)
  greska();
 
 novi->br = br;
 novi->next = NULL;
 
 return novi;
}

void dodaj_na_pocetak(cvor **adresa_liste, int br){
 cvor *novi = napravi_novi(br);
 
 novi->next = *adresa_liste;
 *adresa_liste = novi;
}

void ispis(cvor *lista){
 for(; lista!=NULL ; lista = lista->next)
  printf("%d ", lista->br);
 printf("\n");
}

void ispis_rekurzivno(cvor *lista){
 if(lista==NULL){
  printf("\n");
  return;
 }
 
 printf("%d ", lista->br);
 ispis_rekurzivno(lista->next); 
}

void dodaj_na_kraj(cvor **adresa_liste, int br){
 if(*adresa_liste==NULL){
  dodaj_na_pocetak(adresa_liste, br);
  return;
 }
 
 cvor *poslednji = *adresa_liste;
 for(; poslednji->next !=NULL; poslednji = poslednji->next);
 
 cvor *novi=napravi_novi(br);
 poslednji->next = novi;
}

void oslobodi_listu(cvor *lista){
 // free(lista); - oslobadja samo glavu liste
/* ITERATIVNO
 for(; lista!=NULL; ){
  cvor *glava=lista;
  lista=lista->next;
  free(glava); // ako stavimo free(lista), ne mozemo da pristupimo next 
 } */
 
 //REKURZIVNO
 if(lista==NULL)
  return;
 oslobodi_listu(lista->next);
 free(lista); 
}

// DRUGI ZADATAK
void obrisi_cvor(cvor **lista, int br){
 if(*lista==NULL)
  return;
 
 if((*lista)->br == br){
   cvor *glava = *lista;
   *lista = (*lista)->next;
   free(glava);
   obrisi_cvor(lista, br);
   return;
 }
 
 obrisi_cvor(&((*lista)->next), br);
}

// TRECI ZADATAK
void merge(cvor *lista1, cvor *lista2, cvor **rez){
 if(lista1 == NULL){
  *rez=lista2;
  return;
 }
 if(lista2 == NULL){
  *rez=lista1;
  return;
 }
 
 if(lista1->br < lista2->br){
  cvor *glava = lista1;
  lista1 = lista1->next;
  glava->next = NULL;
  *rez = glava;
  merge(lista1, lista2, &((*rez)->next));
  return;
 }
 
 cvor *glava = lista2;
 lista2 = lista2->next;
 glava->next = NULL;
 *rez = glava;
 merge(lista1, lista2, &((*rez)->next));
 return;
}

// CETVRTI ZADATAK
int veci_od(cvor* lista, int br){
 if(lista==NULL)
  return 0;
 
 if(lista->br > br)
  return 1+veci_od(lista->next, br);
 
 return veci_od(lista->next, br); 
}

// PETI ZADATAK
void obrisi_manjeS(cvor **lista, int suma){
 if(*lista==NULL)
  return;
 
 cvor *glava = *lista;
 int novaSuma = suma + glava->br;
 
 if(glava->br < suma){
  *lista = glava->next;
  free(glava);
  obrisi_manjeS(lista, novaSuma);
  return;
 }
 obrisi_manjeS(&((*lista)->next), novaSuma);
}

void obrisi_manje(cvor *lista){ 
 return obrisi_manjeS(&lista, 0);
}

// SESTI ZADATAK
void dodaj_1(cvor *lista, int k){
 if(lista==NULL)
  return; 
 if(lista->next == NULL)
  return;
 
 cvor *rep = lista->next;
 int zbir = lista->br + rep->br;
 int razlika = abs(lista->br - rep->br);
 
 if(zbir==k || razlika==k){
  cvor *novi = napravi_novi(-1);
  lista->next = novi;
  novi->next = rep;
 }
 
 dodaj_1(rep, k);  
}

// SEDMI ZADATAK
void obrisiZ(cvor **lista, int k){
 if(*lista==NULL)
  return;
 if((*lista)->next == NULL)
  return;
 
 cvor *sledeci = (*lista)->next;
 int br = sledeci->br;
 
 obrisiZ(&((*lista)->next), k);
 
 if((*lista)->br + br == k){
  cvor *glava = *lista;
  if(sledeci == glava->next){
   *lista = sledeci->next;
   free(glava);
   free(sledeci);
  }
  else{
   *lista = glava->next;
   free(glava);
  }
 }  
}

/* Napisati funkcuju koja brise svaki element liste koji je
manji od sume svih prethodnih elemenata u listi. Prilikom
racunanja sume uzeti u obzir i prethodno obrisane elemente.
Kreirati glavni program koji ucitava listu (elementi liste se
ucitavaju sve do unosa broja 0), poziva napisanu funkciju i
ispisuje dobijenu listu na izlaz. U slucaju greske na
standardni izlaz za greske ispisati -1. Napomena: Koristiti
biblioteku za rad sa listama. */

#include <stdio.h>
#include <stdlib.h>
#include "5.h"

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

cvor *napravi_novi(int br){
 cvor *novi = malloc(sizeof(cvor));
 if(novi==NULL)
  greska();
 
 novi->br = br;
 novi->next = NULL;
 
 return novi;
}

void dodaj_na_kraj(cvor **lista, int br){
 if(*lista==NULL){
  cvor *novi = napravi_novi(br);
  *lista = novi;
  return;
 }
 dodaj_na_kraj(&(*lista)->next, br);
}

void ispis(cvor *lista){
 printf("[");
 for(; lista!=NULL ; lista = lista->next){
  printf("%d", lista->br);
  if(lista->next)
   printf(", ");
 }
 printf("]\n");
}

void oslobodi_listu(cvor *lista){
 if(lista){
  oslobodi_listu(lista->next);
  free(lista);
 }
}

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

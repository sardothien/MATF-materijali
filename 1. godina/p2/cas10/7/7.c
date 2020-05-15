/* Napisati funkciju koja u datoj listi izbacuje susedne
elemente ciji je zbir jednak datom broju k. Potrebno je
ispisati tako dobijenu listu na stadardni izlaz. Nije
dozvoljeno koriscenje pomocne liste. Nije dovoljno samo
ispisati trazenu listu vec je potrebno elemente zaista
izbaciti i konstruisati novu listu. Elementi liste su celi
brojevi, lista se unosi sa standarnog ulaza sve dok se ne
unese 0. Nakon unosa elemenata liste unosi se broj k. U
slucaju greske na standardni izlaz za greske ispisati -1.
Napomena: Koristiti biblioteku za rad sa listama. */

#include <stdio.h>
#include <stdlib.h>
#include "7.h"

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

void ispis(cvor *lista){
 printf("[");
 for(; lista!=NULL ; lista = lista->next){
  printf("%d", lista->br);
  if(lista->next)
   printf(", ");
 }
 printf("]\n");
}

void dodaj_na_kraj(cvor **lista, int br){
 if(*lista==NULL){
  cvor *novi = napravi_novi(br);
  *lista = novi;
  return;
 }
 dodaj_na_kraj(&(*lista)->next, br);
}

void oslobodi_listu(cvor *lista){
 if(lista){
  oslobodi_listu(lista->next);
  free(lista);
 }
}

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

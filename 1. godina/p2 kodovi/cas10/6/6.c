/* Napisati funkciju koja u datoj listi izmedju svaka dva
elementa ciji su zbir ili razlika jednaki datom broju k
umece -1. Glavni program ucitava listu (sve do unosa broja 0)
i ceo broj k. Potrebno je ispisati rezultujucu listu na
stadardni izlaz. Nije dozvoljeno koriscenje pomocne liste.
Ne analizirati prvi i poslednji element liste jer oni nemaju
oba suseda. U slucaju greske na standardni izlaz za greske
ispisati -1. Napomena: Koristiti biblioteku za rad sa
listama. */

#include <stdio.h>
#include <stdlib.h>
#include "6.h"

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

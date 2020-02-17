/* Napisati program koji objedinjuje dve sortirane liste u
jednu sortiranu listu. Funkcija ne treba da kreira nove, vec
da samo preraspodeli postojece cvorove. Prva lista se ucitava
iz datoteke cije ime se zadaje kao prvi argument komandne
linije, a druga iz datoteke cije se ime zadaje kao drugi
argument komandne linije. Liste u datotekama su vec
sortirane. Rezultujucu listu ispisati na standardni izlaz.
U slucaju greske na standardni izlaz za greske ispisati -1.
Napomena: Koristiti biblioteku za rad sa listama. */

#include <stdio.h>
#include <stdlib.h>
#include "3.h"

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

void ucitaj_listu(cvor **lista, FILE *f){
 if(f==NULL)
  greska();
 int x;
 while(fscanf(f, "%d", &x)!=EOF)
  dodaj_na_kraj(lista, x); 
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

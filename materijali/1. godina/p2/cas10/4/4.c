/* Napisati funckiju int veci_od(Cvor* lista, int broj); 
koja proverava koliko ima cvorova u listi cija je vrednost 
veca od prosledjenog broja. Iz datoteke koja se zadaje kao
argument komandne linije se ucitavaju elementi liste. Sa
standardnog ulaza se ucitava broj x. Na standardni izlaz
ispisati rezultat izvrsavanja napisane funkcije. U slucaju
greske na standardni izlaz za greske ispisati -1.
Napomena: Koristiti biblioteku za rad sa listama. */

#include <stdio.h>
#include <stdlib.h>
#include "4.h"

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

void oslobodi_listu(cvor *lista){
 if(lista){
  oslobodi_listu(lista->next);
  free(lista);
 }
}

void ucitaj_listu(cvor **lista, FILE *f){
 if(f==NULL)
  greska();
 int x;
 while(fscanf(f, "%d", &x)!=EOF)
  dodaj_na_kraj(lista, x); 
}

int veci_od(cvor* lista, int br){
 if(lista==NULL)
  return 0;
 
 if(lista->br > br)
  return 1+veci_od(lista->next, br);
 
 return veci_od(lista->next, br); 
}

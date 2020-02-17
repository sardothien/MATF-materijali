/* Napisati funkciju void obrisi_cvor(Cvor** lista, int
broj); koja iz prosledjene liste brise sve cvorove cija je
vrednost prosledjeni broj. Testirati funkciju pozivom iz 
main-a. Sa standardnog ulaza se ucitavaju elementi liste,
sve dok se ne unese 0. Zatim se unosi i broj koji treba da
se obrise. Na standardni izlaz ispisati rezultujucu listu. U
slucaju greske na standardni izlaz za greske ispisati -1.
Napomena: Koristiti biblioteku za rad sa listama. */

#include <stdio.h>
#include <stdlib.h>
#include "2.h"

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

void oslobodi_listu(cvor *lista){
 if(lista){
  oslobodi_listu(lista->next);
  free(lista);
 }
}

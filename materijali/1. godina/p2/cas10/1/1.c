/* Napisati biblioteku za rad sa jednostruko povezanim
listama koje sadrze cele brojeve. */

#include <stdio.h>
#include <stdlib.h>
#include "1.h"
// Vraca cvor cija je vrednost prosledjen broj
cvor *napravi_novi(int br){
 cvor *novi = malloc(sizeof(cvor));
 if(novi==NULL)
  greska();
 
 novi->br = br;
 novi->next = NULL;
 
 return novi;
}
// GRESKA
void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}
// Pravi novi cvor cija je vrednost prosledjeni broj
// Postavlja taj cvor na pocetak prosledjene liste
void dodaj_na_pocetak(cvor **lista, int br){
 cvor *novi = napravi_novi(br);
 novi->next = *lista;
 *lista = novi;
}
// Ispisuje prosledjenu listu iterativno
void ispis(cvor *lista){
 printf("[");
 for(; lista!=NULL ; lista = lista->next){
  printf("%d", lista->br);
  if(lista->next)
   printf(", ");
 }
 printf("]\n");
}
// Ispisuje prosledjenu listu rekurzivno
void ispis_rekurzivno(cvor *lista){
 if(lista==NULL){
  printf("\n");
  return;
 } 
 printf("%d ", lista->br);
 ispis_rekurzivno(lista->next);
}
// Pravi novi cvor cija je vrednost prosledjeni broj
// Dodaje taj cvor na kraj prosledjene liste
void dodaj_na_kraj(cvor **lista, int br){
 if(*lista==NULL){
  cvor *novi = napravi_novi(br);
  *lista = novi;
  return;
 }
 dodaj_na_kraj(&(*lista)->next, br);
}
// Iz datoteke f ucitava brojeve do kraja datoteke
// Za svaki ucitani broj pravi novi cvor i dodaje na kraj
void ucitaj_listu(cvor **lista, FILE *f){
 if(f==NULL)
  greska();
 int x;
 while(fscanf(f, "%d", &x)!=EOF)
  dodaj_na_kraj(lista, x); 
}
// Oslobadja memoriju koju zauzima prosledjena lista
void oslobodi_listu(cvor *lista){
 if(lista){
  oslobodi_listu(lista->next);
  free(lista);
 }
}

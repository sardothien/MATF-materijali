#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Cvor{
 int br;
 struct Cvor *next;
} cvor;

void greska();

cvor *napravi_novi(int br);

void dodaj_na_kraj(cvor **lista, int br);

void ucitaj_listu(cvor **lista, FILE *f);

void ispis(cvor *lista);

void oslobodi_listu(cvor *lista);

void merge(cvor *lista1, cvor *lista2, cvor **rez);

#endif

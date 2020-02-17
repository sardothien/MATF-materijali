#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Cvor{
 int br;
 struct Cvor *next;
} cvor;

cvor *napravi_novi(int br);

void greska();

void dodaj_na_pocetak(cvor **lista, int br);

void ispis(cvor *lista);

void ispis_rekurzivno(cvor *lista);

void dodaj_na_kraj(cvor **lista, int br);

void ucitaj_listu(cvor **lista, FILE *f);

void oslobodi_listu(cvor *lista);

#endif

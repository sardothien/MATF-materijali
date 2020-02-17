#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Cvor{
 int br;
 struct Cvor *next;
} cvor;

void greska();

cvor *napravi_novi(int br);

void ispis(cvor *lista);

void dodaj_na_kraj(cvor **lista, int br);

void obrisi_cvor(cvor **lista, int br);

void oslobodi_listu(cvor *lista);

#endif

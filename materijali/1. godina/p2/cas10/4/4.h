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

void oslobodi_listu(cvor *lista);

int veci_od(cvor* lista, int br);

#endif

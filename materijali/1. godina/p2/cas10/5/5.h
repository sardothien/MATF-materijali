#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Cvor{
 int br;
 struct Cvor *next;
} cvor;

void greska();

cvor *napravi_novi(int br);

void dodaj_na_kraj(cvor **lista, int br);

void ispis(cvor *lista);

void oslobodi_listu(cvor *lista);

void obrisi_manjeS(cvor **lista, int suma);

void obrisi_manje(cvor *lista);

#endif

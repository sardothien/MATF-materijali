#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct Cvor{
 int br;
 struct Cvor *next;
} cvor;

//typedef cvor *list;

cvor *napravi_novi(int br);
                         // adresa_liste=lista
void dodaj_na_pocetak(cvor **adresa_liste, int br);

void ispis(cvor *lista);

void ispis_rekurzivno(cvor *lista);

void dodaj_na_kraj(cvor **adresa_liste, int br);

void oslobodi_listu(cvor *lista);

#endif

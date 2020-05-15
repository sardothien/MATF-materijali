#ifndef _LISTE_H_
#define _LISTE_H_

#include<stdio.h>

typedef struct _cvor
{
  int vrednost;
  struct _cvor* sledeci;
}Cvor;

Cvor* napravi_cvor(int broj);

void greska();

void dodaj_na_pocetak(Cvor** lista, int broj);

void ispisi_listu(Cvor* lista);

void dodaj_na_kraj(Cvor** lista, int broj);

void ucitaj_listu(Cvor** lista, FILE* f);

void oslobodi_listu(Cvor* lista);

#endif

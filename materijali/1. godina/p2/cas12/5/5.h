#ifndef _STABLA_H_
#define _STABLA_H_

#include <stdio.h>

typedef struct Cvor{
 int br;
 struct Cvor *levo;
 struct Cvor *desno;
} cvor;

void greska();

cvor *napravi_novi(int x);

void dodaj_u_stablo(cvor **adresa_stabla, int x);

void ucitaj_stablo(cvor **adresa_stabla, FILE *f);

void oslobodi(cvor *stablo);

int broj_jednakih_zbiru_suseda(cvor *koren, cvor *predak);

#endif

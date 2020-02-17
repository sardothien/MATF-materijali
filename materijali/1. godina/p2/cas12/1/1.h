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

void ispis_infiksno(cvor *koren);

void oslobodi(cvor *stablo);

cvor *pretrazi_stablo(cvor *koren, int br);

cvor *najmanji_broj(cvor *koren);

cvor *najveci_broj(cvor *koren);

void obrisi_cvor(cvor **adresa_stabla, int br);

#endif

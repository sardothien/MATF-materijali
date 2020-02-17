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

void obrisi_cvor(cvor **adresa_stabla, int br);

int jednaki(cvor *koren1, cvor *koren2);

int broj_cvorova(cvor *koren);

int broj_listova(cvor *koren);

void ispis_poz_listova(cvor *koren);

int zbir_cvorova(cvor *koren);

cvor *najveci_broj(cvor *koren);

int dubina(cvor *koren);

int br_i_nivo(cvor *koren, int i);

void ispis_i_nivo(cvor *koren, int i);

cvor *max_i_nivo(cvor *koren, int i);

int zbir_i_nivo(cvor *koren, int i);

int zbir_manjih_od_x(cvor* koren, int x);

#endif

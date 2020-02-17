#ifndef _STABLA_H_
#define _STABLA_H_

#include<stdlib.h>
#include<stdio.h>

typedef struct Cvor{
    int vrednost;
    struct Cvor* levo;
    struct Cvor* desno;
}Cvor;

void greska();
Cvor* napravi_cvor(int broj);
void dodaj_u_stablo(Cvor** koren, int broj);
void ucitaj_stablo(Cvor** koren, FILE* ulaz);
void ispisi_stablo(Cvor* koren, FILE* f);
void oslobodi_stablo(Cvor* koren);

#endif

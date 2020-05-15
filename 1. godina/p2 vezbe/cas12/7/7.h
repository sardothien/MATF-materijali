#ifndef _STABLA_H_
#define _STABLA_H_

typedef struct Cvor{
 char slovo;
 int br;
 struct Cvor *levo;
 struct Cvor *desno;
} cvor;

void greska();
 
cvor* napravi_cvor(char c);
 
void dodaj_u_stablo(cvor **adresa_stabla, char c);
 
cvor* napravi_stablo_iz_fajla(FILE* f);
 
cvor *maks_ponavljanja(cvor* koren);
 
void oslobodi(cvor* koren);

#endif

#ifndef _STABLA_H_
#define _STABLA_H_

#include <stdio.h>

/*typedef struct Cvor{
 int br;
 struct Cvor *levo;
 struct Cvor *desno;
} cvor;*/

typedef enum{
 BROJ,
 OPERACIJA
} TipCvora;
 
typedef struct _Cvor{
 int vrednost;
 char operator;
 TipCvora tip;
 struct _Cvor* levo;
 struct _Cvor* desno;
} Cvor;

void greska();
 
Cvor* ucitaj(FILE* f);
 
void ispisi(Cvor* koren);
 
void oslobodi(Cvor* koren);
 
float vrednost(Cvor* koren);

#endif

#ifndef _STEK_H
#define _STEK_H

#include"parser.tab.hpp"

typedef struct {
    unsigned char indeks;
    int akcija;
} Stek;

void stavi(unsigned char s, int x);
void izvrsi_akcije();

void sacuvaj(unsigned char indeks, unsigned char vr);
void inicijalizuj();
unsigned char nadji(unsigned char indeks);

#endif

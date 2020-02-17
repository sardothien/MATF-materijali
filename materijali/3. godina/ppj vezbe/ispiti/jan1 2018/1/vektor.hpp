#ifndef _VEKTOR_H
#define _VEKTOR_H

#include<vector>
using namespace std;

typedef struct Cvor{
    float vr;
    struct Cvor* sled;
} cvor;

cvor* dodaj_na_kraj(cvor* lista, float n);
cvor* novi(float n);
void ispisi(cvor* lista);

int duz(cvor* lista);
cvor* saberi(cvor* l1, cvor* l2);
cvor* oduzmi(cvor* l1, cvor* l2);
cvor* pomnozi(cvor* lista, double n);

float norma(cvor* l);
float skalarno(cvor* l1, cvor* l2);

float ugao(cvor* l1, cvor* l2);

void jednaki(cvor* l1, cvor* l2);

#endif

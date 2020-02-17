#include"stek.hpp"
#define MAX 100

Stek stek[MAX];
int vrh = -1;

void stavi(unsigned char s, int x){
    vrh++;
    stek[vrh].indeks = s;
    stek[vrh].akcija = x;
}

void izvrsi_akcije(){
    while(vrh != 0){
        if(stek[vrh].akcija == UVECANJE)
            sacuvaj(stek[vrh].indeks, nadji(stek[vrh].indeks) + 1);
        else
            sacuvaj(stek[vrh].indeks, nadji(stek[vrh].indeks) - 1);
        vrh--;
    }
    
    vrh = -1;
}

static int niz_prom[MAX];

void inicijalizuj(){
    for(int i = 0; i < MAX; i++)
        niz_prom[i] = -1;
}

void sacuvaj(unsigned char indeks, unsigned char vr){
    niz_prom[indeks] = vr;
}

unsigned char nadji(unsigned char indeks){
    if(niz_prom[indeks] != -1)
        return (unsigned char) niz_prom[indeks];
    else
        return 1;
}

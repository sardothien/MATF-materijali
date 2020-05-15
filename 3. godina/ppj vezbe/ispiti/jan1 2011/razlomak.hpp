#ifndef _RAZLOMAK_H_
#define _RAZLOMAK_H_

typedef struct {
    int im, br;
} Razlomak;

int jednaki(Razlomak* r1, Razlomak* r2);
void ispisi(Razlomak* r);

Razlomak* novi_razl(int br, int im);
Razlomak* saberi(Razlomak* r1, Razlomak* r2);
Razlomak* oduzmi(Razlomak* r1, Razlomak* r2);
Razlomak* pomnozi(Razlomak* r1, Razlomak* r2);
Razlomak* podeli(Razlomak* r1, Razlomak* r2);

#endif

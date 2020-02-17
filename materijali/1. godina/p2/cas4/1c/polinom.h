#ifndef _POLINOM_H_
#define _POLINOM_H_

void greska();

/* a) Funkcija kojom se unose koeficijenti P(x) */
int* unos(int* n);

/* b) Ispisuje se P(x) */
void ispis_polinoma(int *niz, int n);

int max(int m, int n);
int min(int m, int n);

/* v) Sumira 2 polinoma */
int suma_polinoma(int* a, int n, int* b, int m, int** c);

/* g) Polinom se mnozi skalarom */
void mnoz_skalarom(int *a, int n, int c);

/* d) Vrednost P(x) u x preko Horneove seme */
int vr_poly(int* a, int n, int x);

/* dj) Mnozi dva polinoma */
int mul_poly(int* a, int n, int* b, int m, int** c);

#endif

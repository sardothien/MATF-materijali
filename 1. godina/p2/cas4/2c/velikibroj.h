#ifndef _VELIKIBROJ_H_
#define _VELIKIBROJ_H_

/* Struktura kojom se broj reprezentuje nizom cifara */
typedef struct vb{
	int cifre[1000];
	int n;
} VB;
/* Ucitavanje velikog broja iz datoteke */
VB unos(char *s);
/* Ispis velikog broja iz datoteke */
void ispis(VB a);
/* Sabiranje dva velika broja */
VB zbir(VB a, VB b);
/* Poredenje dva velika broja (funkcija vraca -1, 0, ili 1) */
int cmpvb(VB a, VB b);
/* Mnozenje velikog broja cifrom */
VB mnozi_cifrom(VB a, int b);
/* Mnozenje dva velika broja */
VB mnozi(VB a, VB b);

VB nula();

#endif

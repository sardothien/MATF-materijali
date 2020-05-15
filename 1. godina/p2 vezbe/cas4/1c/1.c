#include <stdio.h>
#include <stdlib.h>
#include "polinom.h"

int main(){
 
   int n, *niz, *niz2, m; 
   niz=unos(&n);
   niz2=unos(&m);
 //ispis_polinoma(niz, n);
   printf("\n"); 
// int k;
   int *nizsuma;
/* k=suma_polinoma(niz, n, niz2, m, &nizsuma);
   ispis_polinoma(nizsuma, k);
   printf("\n"); */
// int c;
/* mnoz_skalarom(niz, n, c);
   printf("\n"); */
// int x, p;
/* printf("%d\n", vr_poly(niz, n, x)); */
   int k2;
   k2=mul_poly(niz, n, niz2, m, &nizsuma);
   ispis_polinoma(nizsuma, k2);
 
 free(niz);
 free(nizsuma);
 
 return 0;
}

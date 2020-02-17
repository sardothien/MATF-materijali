/* Napisati rekurzivnu funkciju int skalarni proizvod
(int* a, int* b, int n) koja izracunava skalarni
proizvod dva data vektora (predstavljena nizovima
duzine n). */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int skalarni_proizvod(int* a, int* b, int n){
 if(n==0)
  return 0;
 
 return a[0]*b[0]+skalarni_proizvod(a+1, b+1, n-1);
}

int duzina(int x){
 if(x/10==0)
  return 1;
 return 1+duzina(x/10);
}

void napravi_niz(int *kraj_niza, int broj){
 if(broj/10==0){
  kraj_niza[0]=broj;
  return;
 }
 
 kraj_niza[0]=broj%10;
 napravi_niz(kraj_niza-1, broj/10);
}

int main(){
 int n, m;
 scanf("%d%d", &n, &m);
 int k;
 k=duzina(n);
 int *niz1=NULL;
 niz1=malloc(k*sizeof(int));
 if(niz1==NULL)
  greska();
 k=duzina(m);
 int *niz2=NULL;
 niz2=malloc(k*sizeof(int));
 if(niz2==NULL)
  greska();
 
 napravi_niz(niz1+k-1, n); 
 napravi_niz(niz2+k-1, n); 
 printf("Skalarni proizvod: %d\n", skalarni_proizvod(niz1, niz2, k));
 
 return 0;
}

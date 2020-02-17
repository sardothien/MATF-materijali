/* Napisati rekurzivnu funkciju void napravi_niz(int*
kraj niza, int broj) koja kreira niz cifara datog
celog broja. Napisati rekurzivnu funkciju void ispisi
niz(int* niz, int n) koja ispisuje elemente niza
duzine n. Testirati obe funkcije pozivom iz glavog
programa. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void napravi_niz(int *kraj_niza, int broj){
 if(broj/10==0){
  kraj_niza[0]=broj;
  return;
 }
 
 kraj_niza[0]=broj%10;
 napravi_niz(kraj_niza-1, broj/10);
}

void ispisi_niz(int *niz, int n){
 if(n==0)
  return;
 
 printf("%d ", niz[0]);
 ispisi_niz(niz+1, n-1); 
}

int duzina(int x){
 if(x/10==0)
  return 1;
 return 1+duzina(x/10);
}

int main(){
 int n;
 scanf("%d", &n);
 int k=duzina(n);
 int *niz=NULL;
 niz=malloc(k*sizeof(int));
 if(niz==NULL)
  greska();
 
 napravi_niz(niz+k-1, n);
 ispisi_niz(niz, k);
 printf("\n");
 
 free(niz);
 
 return 0;
}

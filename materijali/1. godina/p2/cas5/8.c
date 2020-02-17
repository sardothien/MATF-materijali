/* Napisati rekurzivnu funkciju void obrni niz(int*
a, int n) koja obrce niz brojeva (niz alocirati
dinamicki). */

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

void obrni_niz(int *a, int n){
  if(n<=1)
    return;
  
  int tmp=*a;
  *a=a[n-1];
  a[n-1]=tmp;
  
  obrni_niz(a+1, n-2);
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
 obrni_niz(niz, k);
 ispisi_niz(niz, k);
 printf("\n");
 
 return 0;
}

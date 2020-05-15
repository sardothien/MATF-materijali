/* Napisati rekurzivnu funkciju int maks_niza(int* a, int n)
koja odreduje maksimum niza celih brojeva. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int maksimum_niza(int* a, int n){
 if(n==1)
  return a[0];
 int max=maksimum_niza(a+1, n-1);
 if(a[0]>max)
  return a[0];
 else
  return max;
}

void napravi_niz(int *kraj_niza, int broj){
 if(broj/10==0){
  kraj_niza[0]=broj;
  return;
 }
 
 kraj_niza[0]=broj%10;
 napravi_niz(kraj_niza-1, broj/10);
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
 printf("Maksimum niza: %d\n", maksimum_niza(niz, k));
 
 return 0;
}

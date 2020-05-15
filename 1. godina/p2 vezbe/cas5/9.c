/* Napisati rekurzivnu funkciju int palindrom(int*
a, int n) koja ispituje da li su elementi nekog niza
brojeva poredjani palindromski (isto od napred i od
pozadi). */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int palindrom(int *a, int n){
 if(n==0 || n==1)
  return 1;
 
 if(a[0]==a[n-1])
  return palindrom(a+1, n-2);
 
 return 0;
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
 printf("Palindrom? %d\n", palindrom(niz, k));
 
 return 0;
}

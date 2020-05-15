/* Napisati rekurzivnu funkciju int izmeniNiz(int niz[],
int n) koja razmenjuje vrednosti i-tog i (n−1−i)-tog
elementa celobrojnog niza ukoliko su i-ti i n−1−i-ti
elementi razlicite parnosti (i=0..n/2). Napisati program
koji sa standardnog ulaza ucitava pozitivan ceo broj n a
zatim n elemenata niza i na standardni izlaz ispisuje
niz izmenjen funkcijom izmeniNiz. U slucaju neispravnih
ulaza na standardni izlaz za greske ispisati -1.
Funkcija noviBroj mora biti rekurzivna sa navedenim
prototipom, u protivnom se resenje boduje sa 0 poena. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int izmeniNiz(int niz[], int n){
 if(n<=1)
  return;
  
 if((niz[0]%2) != (niz[n-1]%2)){
   int tmp=niz[0];
   niz[0]=niz[n-1];
   niz[n-1]=tmp;
 } 
 izmeniNiz(niz+1, n-2);
}

int main(){
 int n;
 scanf("%d", &n);
 if(n<=0)
  greska();
 
 int *niz;
 niz=malloc(n*sizeof(int));
 if(niz==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &niz[i]);
 
 izmeniNiz(niz, n);
 for(i=0; i<n; i++)
  printf("%d ", niz[i]);
 
 printf("\n");
 
 free(niz);
 
 return 0;
}

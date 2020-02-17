/* Napisati program koji u datom nizu brojeva koji su uredjeni
rastuce pronalazi broj koji je po vrednosti najblizi trazenom
broju. Na standarni izlaz ispisati vrednost pronadjenog broja.
U slucaju vise takvih, ispisati najmanji. U slucaju greske na
standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int pretraga(int *niz, int n, int x){
 int i, j;
 int iznad, ispod;
 for(i=0, j=n-1; i<n && j>=0; i++, j--){
  if(niz[i]==x)
   return niz[i];
  else if(niz[i]<x)
   ispod=niz[i];
  else{
   iznad=niz[j];
   break:
  }
 }

 int r1, r2;
 r1=x-ispod;
 r2=iznad-x;
 if(r1>=r2)
  return ispod;
 else
  return iznad;
 
 return -1;
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
 
 int x;
 scanf("%d", &x);
 
 printf("%d\n", pretraga(niz, n, x));
 
 free(niz);
 
 return 0;
}

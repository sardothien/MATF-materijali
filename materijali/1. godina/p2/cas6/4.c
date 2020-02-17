/* Napisati program koji u datom nizu leksikografski
sortiranih reci pronalazi trazenu rec 
a. Binarnom pretragom (rekurzivno ili iterativno) 
b. Binarnom pretragom, koristeci funkciju bsearch
Ukoliko je element nadjen, na standarni izlaz ispisati
njegovu poziciju (broji se od 0), a u suprotnom -1.
U slucaju greske na standardni izlaz za greske ispisati
-1. Sa standardnog ulaza se prvo zadaje broj reci, a
zatim i same reci. Nakon toga se zadaje rec koja se
trazi. Maksimalna duzina jedne reci je 20 karaktera. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}
// POD a)
int binarna_rekurzivno(char **niz, int l, int d, char *trazena){
 if(l>d)
  return -1;
 
 int s=l+(d-l)/2;
 int rez=strcmp(niz[s], trazena);
 if(rez==0)
  return s;
 else if(rez>0)
  return binarna_rekurzivno(niz, l, s-1, trazena);
 else
  return binarna_rekurzivno(niz, s+1, d, trazena);
}
// POD b)
int poredi(const void *a, const void *b){
 return strcmp((char*)a, *(char**)b);
}

int main(){
 int n;
 scanf("%d", &n);
 if(n<=0)
  greska();
 
 char **niz_reci;
 char trazena_rec[MAX];
 
 niz_reci=malloc(n*sizeof(char*));
 if(niz_reci==NULL)  
  greska();
 
 int i;
 for(i=0; i<n; i++){
  niz_reci[i]=malloc(MAX);
  if(niz_reci[i]==NULL)
   greska();
  scanf("%s", niz_reci[i]);
 }
 
 scanf("%s", trazena_rec);
 
 int k=binarna_rekurzivno(niz_reci, 0, n-1, trazena_rec);
 printf("Pod a): %d\n", k);
 
 char **p=bsearch(trazena_rec, niz_reci, n, sizeof(char*), poredi);
 if(p==NULL)
  greska();
 else
  printf("Pod b): %ld\n", p-niz_reci);
 
 
 for(i=0; i<n; i++)
  free(niz_reci[i]);
 free(niz_reci);
 
 return 0;
}

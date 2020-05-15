/* Napisati program koji sa standardnog ulaza
ucitava dimenziju niza celih brojeva, a zatim i 
njegove elemente. Na standardni izlaz za svaki broj
ispisati koliko ima brojeva koji se nalaze ispred
njega u nizu, a koji su manji od tog broja. U slucaju
greske na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(){
 int n, *niz;
 niz=(int*)malloc(n*sizeof(int));
 if(niz==NULL)
  greska();
 
 scanf("%d", &n); 
 if(n<=0)
  greska();
 
 int i=0;
 for(i=0; i<n; i++)
  scanf("%d", &niz[i]);
 
 int br=0, j;
 for(i=0; i<n; i++){
  br=0;
  for(j=0; j<i; j++){
   if(niz[j]<niz[i]){
    br++;
   }
  }
  printf("%d ", br);  
 }
 printf("\n");
 
 free(niz);
 
 return 0;
}

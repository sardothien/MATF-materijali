/* Napisati program koji sa standardnog
ulaza ucitava dimenziju niza celih brojeva,
a zatim i njegove elemente. Ne praviti 
pretpostavke o dimenziji niza. Na standardni 
izlaz ispisati ucitane brojeve u obrnutom
poretku. U slucaju greske na standardni izlaz
ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 int n;
 int *niz;
 
 scanf("%d", &n);
 
 niz=(int *)malloc(n*sizeof(int));
 if(niz==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int i;
 for(i=0; i<n; i++){
  scanf("%d", &niz[i]);
 }
 
 for(i=n-1; i>=0; i--){
  printf("%d ", niz[i]);
 }
 
 free(niz);
 printf("\n");
 
 return 0;
}

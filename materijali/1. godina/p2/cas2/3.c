/* Napisati program koji ucitava niz celih brojeva
iz datoteke brojevi.txt sve do unosa broja 0,
koristeci funkciju za realokaciju memorije sa korakom
k (koji se zadaje kao argument komandne linije). Na
standardni izlaz ispisati sve brojeve koji su veci od
sredisnjeg elementa niza. U slucaju parne dimenzije
niza, sredisnji element racunati kao aritmeticku sredinu
dva elementa najbliza sredini. U slucaju greske na
standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
 if(argc!=2){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int k=atoi(argv[1]);
 int korak=k;
 
 FILE *brojevi=fopen("brojevi.txt","r");
 if(brojevi==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int *niz;
 niz=(int *)malloc(k*sizeof(int));
 if(niz==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int i=0;
 int br;
 while(1){
  fscanf(brojevi, "%d", &br);
  if(br==0){
   break;
  }
  niz[i++]=br;
  if(i==k){
   k=k+korak;
   niz=realloc(niz, k);
   if(niz==NULL){
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
   }
  }
 }
 
 fclose(brojevi);
 
 int n=i;
 float sredina;
 if(n%2==0){
  sredina=((float)niz[n/2]+niz[n/2-1])/2;
 }
 else{
  sredina=niz[n/2];
 }
 
 for(i=0; i<n; i++){
  if(niz[i]>sredina){
   printf("%d ", niz[i]);
  }
 }
 
 free(niz);
 printf("\n");
 
 return 0;
}

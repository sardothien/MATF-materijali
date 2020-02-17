/* Napisati program koji postavlja na k-to mestu jedinicu u
celom broju x. Celi brojevi k (neoznacen ceo broj) i x se
unose sa standarnog ulaza. Pozicija se broji od najmanje
tezine ka najvecoj pocevsi od 0. */

#include <stdio.h>

int postavi_1(int x, unsigned k){
 unsigned maska = 1<<k;
 return maska | x;
}

int main(){
 int x;
 unsigned k;
 scanf("%d%u", &x, &k);
 if(k<0 || k>=32){
  printf("pozicija nije u dobrom opsegu\n");
  return -1;
 }
 
 printf("%d\n", postavi_1(x, k));
 
 return 0;
}

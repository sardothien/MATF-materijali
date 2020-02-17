/* Napisati program koji proverava da li je na k-tom mestu
jedinica u celom broju x. Celi brojevi k (neoznacen ceo broj)
i x se unose sa standarnog ulaza. Pozicija se broji od
najmanje tezine ka najvecoj pocevsi od 0. Ukoliko pozicija
nije u dobrom opsegu ispisati poruku o gresci. */

#include <stdio.h>

int provera(int x, unsigned k){
 unsigned maska=1<<k;
 return maska & x;
}

int main(){
 int x;
 unsigned k;
 scanf("%d%u", &x, &k);
 if(k<0 || k>=32){
  printf("pozicija nije u dobrom opsegu\n");
  return -1;
 }
  
 int l=provera(x, k);
 if(l)
  printf("jeste\n");
 else 
  printf("nije\n");
 
 return 0;
}

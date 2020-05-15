/* Napisati funkciju koja u rastuće sortiranom nizu
celih brojeva binarnom pretragom pronalazi indeks prvog
elementa većeg od nule. Ukoliko nema elemenata većih od
nule, funkcija kao rezultat vraća −1. Napisati program
koji testira ovu funkciju za rastući niz celih brojeva
koji se učitavaju sa standardnog ulaza. Niz neće biti
duži od 256, i njegovi elementi se unose sve do kraja
ulaza. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int prvi_veci_od_nule(int niz[],int i){
 int l=0, d=i-1;
 int sr;
 while(l<=d){
  sr=(l+d)/2;
  if(niz[sr]>0 && ((sr>0 && niz[sr-1]<=0) || sr==0))
   return sr;
  if(niz[sr]<0)
   l=sr+1;
  else
   d=sr-1;
 }
 return -1;
}

int main(){
 int niz[256];
 int i=0;
 while(scanf("%d", &niz[i])==1)
  i++;
 
 printf("%d\n", prvi_veci_od_nule(niz, i));
 
 return 0;
}

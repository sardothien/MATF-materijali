/* Napisati funkciju suma_bitova koja izracunava sumu bitova
datog broja. Testirati funkciju pozivom u main-u, broj x se
unosi sa standarnog ulaza. */

#include <stdio.h>

int suma_bitova(int x){
 unsigned n=sizeof(x)*8;
 unsigned maska=1<<(n-1);
 int suma=0;
 while(maska){
  if(x&maska)
   suma++;
  maska >>= 1;
 }
 return suma;
}

int main(){
 int x;
 scanf("%d", &x);
 
 printf("%d\n", suma_bitova(x)); 
 
 return 0;
}

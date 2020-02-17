/* Napisati program koja broji koliko se puta kombinacija 11
(dve uzastopne jedinice) pojavljuje u binarnom zapisu celog
broja x. Broj x se unosi sa standarnog ulaza, a rezultat se
ispisuje na standarni izlaz. */

#include <stdio.h>

int suma(int x){
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

int brojanje(unsigned x){
 unsigned maska=3;
 int n=sizeof(unsigned)*8-1;
 int br=0;
 while(n>1){
  if(suma(maska&x)==2)
   br++;
  n--;
  maska <<= 1;
 }  
 return br;
}

int main(){
 int x;
 scanf("%d", &x);
 
 printf("%d\n", brojanje(x));
  
 return 0;
}

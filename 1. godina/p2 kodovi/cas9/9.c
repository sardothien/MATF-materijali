/* Napisati funkciju unsigned mirror(unsigned x) koja obrce
zapis broja x. Testirati funkciju pozivom u main-u. Broj x se
unosi sa standarnog ulaza. Na standarni izlaz ispisati
binarnu reprezentaciju broja x i novodobijnog broja. */

#include <stdio.h>

void print_bits(int x){
 unsigned n=sizeof(x)*8;
 unsigned maska=1<<(n-1);
 while(maska){
  if(x&maska)
   putchar('1');
  else
   putchar('0');
  maska >>= 1;
 }
}

unsigned mirror(unsigned x){
 unsigned maska=1;
 unsigned rez=0;
 while(maska){
  if(x&maska){
   rez <<= 1;
   rez |= 1;
  }
  else
   rez <<= 1;
  maska <<= 1;
 }
 return rez;
}

int main(){
 unsigned x;
 scanf("%u", &x);
 
 print_bits(x);
 printf("\n"); 
 print_bits(mirror(x));
 printf("\n"); 
 
 return 0;
}

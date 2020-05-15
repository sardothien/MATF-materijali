/* Napisati funkciju unsigned right_rotate(unsigned x, int n)
koja vrsi rotaciju neoznacenog broja x za n pozicija u desno.
Testirati funkciju pozivom u main-u. Brojevi x i n se unose
sa standarnog ulaza. Na standarni izlaz ispisati binarnu
reprezentaciju broja x i novodobijnog broja. Ukoliko je broj 
n negativan ispisati poruku o gresci. */

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

unsigned right_rotate(unsigned x, int n){
 unsigned mask=1;
 unsigned mask1=0;
 int i;
 for(i=0; i<n; i++, mask <<= 1)
  mask1 = mask1 | mask;
 mask1 = mask1&x;
 mask1 = mask1 << (sizeof(unsigned)*8-n);
 x = x >> n;
 return x^mask1; 
}

int main(){
 unsigned x;
 int n;
 scanf("%u", &x);
 scanf("%d", &n);
 
 if(n<0){
  printf("greska u stepenu rotacije\n");
  return -1;
 }
 
 print_bits(x);
 printf("\n"); 
 print_bits(right_rotate(x, n));
 printf("\n"); 
 
 return 0;
}

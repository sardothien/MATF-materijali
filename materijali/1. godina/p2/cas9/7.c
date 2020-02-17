/* Napisati funkciju unsigned invert_bits(unsigned x, int p,
int n) koja invertuje n bitova broja x pocevsi od pozicije p.
Testirati funkciju pozivom u main-u, pri cemu se brojevi x, p
i n unose sa standarnog ulaza. Proveriti da li su brojevi p i
p+n u odgovarajucem opsegu i ispisati poruku o gresci ako
nisu. Na standarni izlaz ispisati bitove unesenog broja x i
bitove novodobijenog broja. */

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

unsigned invert_bits(unsigned x, int p, int n){
 unsigned mask=1;
 unsigned mask1=0;
 int i;
 for(i=0; i<n; i++, mask <<= 1)
  mask1 = mask1 | mask;
 mask1 = mask1 << p;
 return x^mask1;
}

int main(){
 unsigned x;
 int p, n;
 scanf("%u", &x);
 scanf("%d%d", &n, &p);
 
 if(p<0 || p+n>=sizeof(int)*8){
  printf("pozicija nije u dobrom opsegu\n");
  return -1;
 }
 
 print_bits(x);
 printf("\n"); 
 print_bits(invert_bits(x, p, n));
 printf("\n"); 
 
 return 0;
}

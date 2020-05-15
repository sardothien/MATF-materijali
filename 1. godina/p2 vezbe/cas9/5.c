/* Napisati funkciju unsigned get_bits(int x, int p, int n)
koja vraca broj dobijen od broja x tako da mu je izdvojeno n
bita pocev od pozicije p, a ostalo su 0. Testirati funkciju
pozivom u main-u, pri cemu se brojevi x, p i n unose sa
standarnog ulaza. Proveriti da li su brojevi p i p+n u
odgovarajucem opsegu i ispisati poruku o gresci ako nisu. Na
standarni izlaz ispisati bitove unesenog broja x i bitove
novodobijenog broja. */

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

unsigned get_bits(int x, int p, int n){
 unsigned maska = ~(~0<<n) << (p-n+1);
 return maska & x;
}

int main(){
 int x, p, n;
 scanf("%d%d%d", &x, &n, &p);
 
 print_bits(x);
 printf("\n"); 
 print_bits(get_bits(x, p, n));
 printf("\n"); 
 
 return 0;
}

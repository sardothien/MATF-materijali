/* Napisati funkciju unsigned set_bits(unsigned x, int p, int
n, unsigned y) koja vraca modifikovano x tako sto mu je
izmenjeno n bitova pocevsi od pozicije p i na ta mesta je
upisano poslednjih n bitova broja y. Testirati funkciju
pozivom u main-u, pri cemu se brojevi x, y, p i n unose sa
standarnog ulaza. Proveriti da li su brojevi p i p+n u
odgovarajucem opsegu i ispisati poruku o gresci ako nisu. Na
standarni izlaz ispisati bitove unesenog broja x i y i bitove
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

unsigned set_bits(unsigned x, int p, int n, unsigned y){
 unsigned y_bits = ~(~0<<n)&y;
 y_bits <<= p-n+1;
 unsigned maska = ~(~(~0<<n)<<(p-n+1));
 return (x&maska) | y_bits;
}

int main(){
 unsigned x, y;
 int p, n;
 scanf("%u%u", &x, &y);
 scanf("%d%d", &n, &p);
 
 if(p<0 || p+n>=sizeof(int)*8){
  printf("pozicija nije u dobrom opsegu\n");
  return -1;
 }
 
 print_bits(x);
 printf("\n");
 print_bits(y);
 printf("\n"); 
 print_bits(set_bits(x, p, n, y));
 printf("\n"); 
 
 return 0;
}

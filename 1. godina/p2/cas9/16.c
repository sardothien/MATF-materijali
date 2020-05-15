/* Sa standarnog ulaza ucitava se neoznacen ceo broj x,
neoznacen ceo broj n i niz od n celih neoznacenih brojeva
(n≤32). Odrediti neoznacen ceo broj y koji se dobija na 
sledeci nacin: porede se i-ti bit broja x i i-ti bit i-tog
broja niza. Ukoliko su jednaki na i-to mesto broja y se
postavlja bit 1, a inace se postavlja 0 (ukoliko i-ti broj
niza ne postoji, podrazumevati da je vrednost odgovarajuceg
bita 0). Ispisati broj y na standardni izlaz. U slucaju
greske ispisati -1 na standardni izlaz. */

#include <stdio.h>

int main(){
 unsigned int x;
 unsigned int n;
 unsigned int niz[32];
 scanf("%u", &x);
 scanf("%u", &n);
 
 int i;
 for(i=0; i<n; i++)
  scanf("%u", &niz[i]);
	
 unsigned rez=0;
 unsigned int mask=1;
 for(i=0; i<32; i++){
  unsigned prvi = x&mask;
  unsigned drugi=0;
  if(i<n)
   drugi = niz[i] & mask;
  if(prvi==drugi)
   rez = rez | mask;
  mask = mask << 1;
 }
 
 printf("%u\n", rez);
 
 return 0;
}

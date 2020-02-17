/* Sa standardnog ulaza se unosi ceo broj n (n≤32), a zatim i
niz od n neoznacenih celih brojeva. Formirati neoznaceni ceo
broj x tako sto se na i-ti bit broja x postavlja vrednost 
i-tog bita i-tog broja niza. Broj x ispisati na standardni
izlaz. Bitove broja citati od pozicija manje tezine ka
pozicijama vece tezine. Podrazumevana vrednost bitova broja x
je 0. U slucaju greske ispisati −1 na standardni izlaz. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 printf("-1\n");
 exit(EXIT_FAILURE);
}

int main(){
 int n;
 scanf("%d", &n);
 if(n<0 || n>32)
  greska();
 
 unsigned niz[32];
 int i;
 for(i=0; i<n; i++)
  scanf("%u", &niz[i]);
	
 unsigned x=0;
 unsigned mask=1;
	
 for(i=0; i<n; i++){
  unsigned t = mask&niz[i];
  x = x|t;
  mask = mask<<1;
 }
	
 printf("%u\n", x);
	
 return 0;
}

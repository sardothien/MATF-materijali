/* Napisati program koji učitava ceo pozitivan broj n i ispisuje vrednost sume kubova brojeva od 1 do n, odnosno s=1+2^3+3^3+...+n^3. U slučaju greške pri unosu podataka ispisati odgovarajuću poruku. */

#include <stdio.h>
#include <ctype.h>

int main(){

 int n, i, s;
 scanf("%d", &n);
 
 if(n<=0){
  printf("-1\n");
  return -1;
 }
 
 for(i=1; i<=n; i++){
  s=s+i*i*i;
 }

 printf("%d\n", s);

 return 0;
}

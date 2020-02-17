/* Napisati program koji učitava ceo pozitivan broj n i ispisuje sumu kubova, s=1+2^3+3^3+...+k^3, za svaku vrednost k=1,...,n.. U slučaju greške pri unosu podataka ispisati odgovarajuću poruku. */

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
  printf("i=%d s=%d\n", i, s);
 }

 return 0;
}

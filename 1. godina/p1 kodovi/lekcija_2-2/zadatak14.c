/* Program učitava ceo pozitivan broj n, a potom n celih brojeva. Naći sumu brojeva koji su deljivi sa 5, a nisu deljivi sa 7. U slučaju greške pri unosu podataka ispisati odgovarajuću poruku. */

#include <stdio.h>
#include <stdlib.h>

int main() {

 int n, m, s=0;
 
 scanf("%d", &n);
 
 if(n<0){
  printf("-1\n");
  return -1;
 }
 
 while(n>0){
  scanf("%d", &m);
  if(abs(m)%5==0 && abs(m)%7!=0){
   s=s+m;
  }
  n--;
 }
 
 printf("Suma: %d\n", s);

 return 0;
}

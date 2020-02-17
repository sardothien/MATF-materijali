/* NE RADI */
/* Program učitava ceo pozitivan broj n, a potom n realnih brojeva. Odrediti koliko puta je prilikom unosa došlo do promene znaka. Ispisati dobijenu vrednost. */

#include <stdio.h>
#include <stdlib.h>

int main() {

 int n, poz=0, neg=0, r;
 float m;
 scanf("%d", &n);
 
 if(n<=0){
  printf("-1\n");
  return -1;
 }
 
 while(n>0){
  scanf("%f ", &m);
  if(m>0){
   poz++;
  }
  else if(m<0){
   neg++;
  }
  n--;
 }
 r=poz-neg;
 printf("Broj promena: %d\n", abs(r));
   
 return 0;
}

/* Pravi delioci celog broja su svi delioci sem jedinice i samog tog broja. Napisati program za uneti ceo pozitivan broj x ispisuje sve njegove prave delioce. U slučaju greške pri unosu podataka ispisati odgovarajuću poruku. */

#include <stdio.h>

int main() {

 int x, i;
 
 scanf("%d", &x);
 
 if(x<0){
  printf("-1\n");
  return -1;
 }

 for(i=2; i<x; i++){
  if(x%i==0){
   printf("%d ", i);
  }
 }

 return 0;
}

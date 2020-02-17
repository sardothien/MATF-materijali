/* Napisati program koji učitava ceo pozitivan broj i izračunava njegov faktorijel. U slučaju neispravnog unosa ispisati odgovarajuću poruku. */

#include <stdio.h>

int main(){
 
 int n, i;
 unsigned long f=1;
 
 scanf("%d", &n);
 
 if(n<0){
  printf("-1\n");
  return -1;
 }
 if(n>22){
  printf("Dolazi do prekoracenja.\n");
  return 0;
 }
 
 for(i=1; i<=n; i++){
  f=f*i;
 }
 printf("%lu\n", f);

 return 0;
}

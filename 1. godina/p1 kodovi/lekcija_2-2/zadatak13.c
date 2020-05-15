/* Program unosi ceo pozitivan broj n, a potom i n celih brojeva. Izračunati i ispisati zbir onih brojeva koji su neparni i negativni. */

#include <stdio.h>
#include <stdlib.h>

int main() {

 int n, m, x, s=0;
 
 scanf("%d", &n);
 
 if(n<=0){
  printf("-1\n");
  return -1;
 }
 
 while(n>0){
  scanf("%d", &m);
  if(m<0 && abs(m)%2==1){
   s=s+m;
  }
  n--;
 }
 
 printf("Suma neparnih i negativnih: %d\n", s);

 return 0;
}

/* FEBRUAR - 2017 zadatak 1
Napisati program kojim se sa standardnog ulaza unose celi brojevi do
unosa broja 0 i ispisuju oni brojevi koji imaju neparan broj cifara.
Broj brojeva nije unapred poznat. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 int x, cx, y, bn=0, i;
 
 while(1){
  scanf("%d", &x);
  if(x==0){
   break;
  }
  cx=x;
  x=abs(x);
  bn=0;  
  while(x>0){
   x/=10;
   bn++;
  }
  if(bn%2!=0){
   printf("%d ", cx);
  }
 }
 printf("\n");
 
 return 0;
}

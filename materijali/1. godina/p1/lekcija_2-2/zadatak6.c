/* Sa standradnog ulaza unose se realan broj x i ceo pozitivan broj n. Napisati program koji izračunava n-ti stepen broja x, tj. x n . */

#include <stdio.h>
#include <stdlib.h>

int main(){
 
 float x, s=1;
 int n, i;
 
 scanf("%f%d", &x, &n);
 if(n<0){
  printf("-1\n");
  return -1;
 }

 for(i=1; i<=n; i++){
  s=s*x; 
 }
 
 printf("%.3f\n", s);
 
 return 0;
}

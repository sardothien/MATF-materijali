/* Sa standradnog ulaza unose se realan broj x i ceo broj n. Napisati program koji izračunava n-ti stepen broja x. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 
 float x, s=1;
 int n, i;
 
 scanf("%f%d", &x, &n);
 
 for(i=1; i<=abs(n); i++){
  s=s*x; 
 }
 
 if(n<0){
  s=1/s;
 }
 
 printf("%.3f\n", s);
 
 return 0;
}

/* Napisati funkciju float stepen(float x, int n) koja
računa vrednost n-tog stepena realnog broja x. Napisati program koji učitava
relan broj x i ceo broj n i ispisuje rezultat rada funkcije. */

#include <stdio.h>
#include <stdlib.h>

float stepen(float x, int n){

  float s=1;
  int i, absn=abs(n);
  
  for(i=1; i<=absn; i++){
   s*=x;
  }
  
  return n < 0 ? 1.0/s : s;
}


int main(){
 
 float x;
 int n;
 
 scanf("%f%d", &x, &n);
 
 printf("%f\n", stepen(x, n));
 
 return 0;
}

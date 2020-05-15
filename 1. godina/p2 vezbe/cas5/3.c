/* Napisati rekurzivnu funkciju int najveca cifra
(int x) koja racuna najvecu cifru datog celog
broja x. */

#include <stdio.h>

int najveca_cifra(int x){
 if(x/10==0)
  return x;
 
 int max=najveca_cifra(x/10);
 if(x%10>max)
  return x%10;
 else
  return max;
}

int main(){
 int n;
 scanf("%d", &n);
 
 printf("Najveca cifra: %d\n", najveca_cifra(n));
 
 return 0;
}

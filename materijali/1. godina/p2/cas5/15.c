/* Napisati rekurzivnu funkciju int izbaci_parne(int x) koja
izbacuje sve parne cifre datog celog broja x. */

#include <stdio.h>

int izbaci_parne(int x){
 if(x<10)
  if(x%2==0)
   return 0;
  else
   return x;
 
 int levi_deo=izbaci_parne(x/10);
 if(x%2==0)
  return levi_deo;
 else
  return levi_deo*10+x%10;
}

int main(){
 int n;
 scanf("%d", &n);
 
 printf("Novi broj: %d\n", izbaci_parne(n));
 
 return 0;
}

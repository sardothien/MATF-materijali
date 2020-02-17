/* Napisati rekurzivnu funkciju int broj parnih(int x)
koja racuna broj parnih cifara datog celog broja x. */

#include <stdio.h>

int broj_parnih(int x){
 if(x/10==0)
  return x%2==0 ? 1:0;
 
 if(x%2==0)
  return 1+broj_parnih(x/10);
 else
  return broj_parnih(x/10);
}

int main(){
 int n;
 scanf("%d", &n);
 
 printf("Broj parnih: %d\n", broj_parnih(n));
 
 return 0;
}

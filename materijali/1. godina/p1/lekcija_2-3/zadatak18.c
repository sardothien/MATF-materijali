/* Napisati funkciju int par_nepar(int n) koja ispituje da li su
cifre datog celog broja naizmenično parne i neparne. Funkcija treba da
vrati vrednost 1 ako cifre ispunjavaju uslov, odnosno 0 ako ne
ispunjavaju uslov. Napisati i program koji učitava ceo broj i testira
rad funkcije. */

#include <stdio.h>
#include <stdlib.h>

int par_nepar(int n){
 int tekuca_cifra, preth_cifra;
 n=abs(n);
 preth_cifra=n%10;
 n/=10;
 
 while(n){
  tekuca_cifra = n%10;
  if(tekuca_cifra % 2 == preth_cifra % 2){
   return 0;
  }
  preth_cifra = tekuca_cifra;
  n=n/10;
 }
 return 1;
}

int main(){

 int n;
 scanf("%d", &n);
 
 printf("%d\n", par_nepar(n));
 
 return 0;
}

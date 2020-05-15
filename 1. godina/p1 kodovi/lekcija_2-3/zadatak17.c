/* Napisati funkciju int rastuce(int n) koja ispituje da li su cifre
datog celog broja u rastućem poretku. Funkcija treba da vrati vrednost
1 ako cifre ispunjavaju uslov, odnosno 0 ako ne ispunjavaju uslov.
Napisati program koji učitava ceo broj i ispisuje poruku da li su
cifre unetog broja u rastućem poretku. */

#include <stdio.h>
#include <stdlib.h>

int rastuce(int n){
 int tekuca_cifra, preth_cifra;
 n=abs(n);
 tekuca_cifra=n%10;
 n/=10;
 
 while(n){
  preth_cifra = tekuca_cifra;
  tekuca_cifra = n%10;
  if(preth_cifra < tekuca_cifra){
   return 0;
  }
  n=n/10;
 }
 return 1;
}

int main(){

 int n;
 scanf("%d", &n);
 
 printf("%d\n", rastuce(n));
 
 return 0;
}

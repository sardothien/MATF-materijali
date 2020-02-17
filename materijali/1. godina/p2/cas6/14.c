/* Napisati funkciju koja određuje nulu funkcije cos(x)
na intervalu [0, 2] metodom polovljenja intervala.
Algoritam se završava kada se vrednost kosinusne
funkcije razlikuje za najviše 0.001 od nule. Uputstvo:
Korisiti metod polovljenja intervala (algoritam analogan
algoritmu binarne pretrage). Napomena: Ovaj metod se
može primeniti na funkciju cos(x) na intervalu [0, 2]
zato što je ona na ovom intervalu neprekidna, i
vrednosti funkcije na krajevima intervala su različitog
znaka. */

#include <stdio.h>
#include <math.h>

#define EPS 0.001

int main(){
 double levo=0, desno=2;
 double sr;
 while(1){
  sr=levo+(desno-levo)/2;
  if(fabs(cos(sr))<EPS)
   break;
  if(cos(levo)*cos(sr)<0)
   desno=sr;
  else
   levo=sr;
 }
 
 printf("%g\n", sr);
 
 return 0;
}

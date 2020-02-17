/* 2015/2016 - Kolokvijum GRUPA 3, zadatak 3 */
/* Napisati C program koji sa standardnog ulaza ucitava dva cetvorocifrena, pozitivna, cela broja i proverava da li je broj koji se dobija ucesljavanjem unetih brojeva palindrom. Ako uneti brojevi imaju cifre 67a1 a2 a3 a4 i b1 b2 b3 b4 tada su cifre ucesljanog broja a1 b1 a2 b2 a3 b3 a4 b4. Broj je palindrom ako se cita isto sa obe strane. Ukoliko je broj palindrom ispisati na standardni izlaz 1, ukoliko nije tada ispisati 0, a u slucaju neispravnog ulaza ispisati -1, neispravnim ulazom smatraju se negativni brojevi i brojevi sa brojem cifara manjim ili vecim od 4. */

#include <stdio.h>

int main(){

 int x, y;
 int x1, x10, x100, x1000, y1, y10, y100, y1000;
 
 scanf("%d%d", &x, &y);
 
 if(x<1000 || x>9999 || y<1000 || y>9999){
  printf("-1\n");
  return -1;
 }

 x1=x%10;
 x10=(x/10)%10;
 x100=(x/100)%10;
 x1000=x/1000;
 y1=y%10;
 y10=(y/10)%10;
 y100=(y/100)%10;
 y1000=y/1000;
 
 if((x1==y1000) && (x10==y100) && (x100==y10) && (x1000=y1)){
  printf("1\n");
 }
 else{
  printf("0\n");
 }

 return 0;
}

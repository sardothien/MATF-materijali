/* 2016/2017 - Predlog kolokvijuma GRUPA 3, zadatak 2 */
/* Napisati program koji za dva uneta pozitivna dvocifrena broja, ako je prvi broj veci, ispisuje broj koji
se dobija tako sto se dva uneta broja spoje, pa im se zatim izbace sve cifre cija je vrednost paran broj,
a u suprotnom ispisuje broj koji se dobija spajanjem dva uneta broja, a zatim izbacivanjem svih cifara
cija je vrednost neparan broj. U slucaju greke, na standardni izlaz ispisati -1. */

#include <stdio.h>

int main(){

 int x, y, z;
 int x1, x10, y1, y10;
 scanf("%d%d", &x, &y);
 
 if(x<0 || y<0){
  printf("-1\n");
  return -1;
 }
 if((x<10 || x>99) || (y<10 || y>99)){
  printf("-1\n");
  return -1;
 }
 
 x1=x%10;
 x10=x/10;
 y1=y%10;
 y10=y/10;
 
 if(x>y){
  z=x10*1000+x1*100+y10*10+y1;
  if(x10%2==0){
   z=z-x10*1000;
  }
  if(x1%2==0){
   z=z-x1*100;
  }
  if(y10%2==0){
   z=z-y10*1000;
  }
  if(y1%2==0){
   z=z-y1;
  }
 }
 else{
  z=x10*1000+x1*100+y10*10+y1;
  if(x10%2==1){
   z=z-x10*1000;
  }
  if(x1%2==1){
   z=z-x1*100;
  }
  if(y10%2==1){
   z=z-y10*10;
  }
  if(y1%2==1){
   z=z-y1;
 }
 }
 
 printf("%d\n", z);

 return 0;
}

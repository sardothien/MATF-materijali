/* Program ucitava ceo broj. Odrediti broj koji se dobija
izbacivanjem svih cifara koje su vece od aritmetike sredine
svih cifara u zapisu unetog broja. Pri tome, ne menjati znak
broja. Potrebno je zaista kreirati novi broj, a ne samo
ispisati cifre u nekom poretku. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 
 int x, c, s=0, br=0, x1, rez=0, p=1;
 int znak;
 float as;
 
 scanf("%d", &x);
 znak = x<0 ? -1:1;
 
 x=abs(x); 
 x1=x;
 
 while(x>0){
  c=x%10;
  br++;
  s+=c;
  x=x/10;
 }
 as=s/br;

 while(x1>0){
  if(x1%10<=as){
   rez=rez+(x1%10)*p;
   p=p*10;
  }
  x1=x1/10;
 }
 
 printf("%d\n", znak*rez);
 return 0; 
}

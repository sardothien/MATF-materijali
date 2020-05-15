/* Program ucitava ceo broj. Odrediti broj koji se dobija izbacivanjem parnih
cifara iz polaznog broja. Pri tome, ne menjati znak broja. Potrebno je zaista
kreirati novi broj, a ne samo ispisati cifre u nekom poretku. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 int x, nx, c, z=0, p=1;
 int znak;
 
 scanf("%d", &x);
 znak = x<0 ? -1 : 1;
 
 x=abs(x);
 
 nx=x;
 while(x>0){
  c=x%10;
  if(c%2!=0){
   z=z+p*c;
   p=p*10;   
  }
  x=x/10;
 }
  
 printf("%d\n", znak*z); 
 
 return 0;
}

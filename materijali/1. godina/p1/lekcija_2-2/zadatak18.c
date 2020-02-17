/* Program učitava cele brojeve sve do unosa broja nula 0. Napisati program koji izračunava i ispisuje aritmetičku sredinu unetih brojeva na četiri decimale. */

#include <stdio.h>

int main() {

 int x, br=0; 
 float as=0;
 
 while(1){
  scanf("%d", &x);
  if(x==0){
   break;
  }
  as=as+x; 
  br++;
  
 }
 
 if(br>0){
  printf("Aritmeticka sredina: %.4f\n", as/br);
 }
 else if(br==0){
  printf("Nisu uneti brojevi.\n");
 } 
   
 return 0;
}

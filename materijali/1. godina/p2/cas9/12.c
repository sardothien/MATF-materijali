/* a) Napisati program koji odredjuje najveci pozitivan broj
koji se moze zapisati istim binarnim ciframa kao dati broj.
   b) Napisati funkciju koja odreduje najmanji pozitivan broj
koji se moze zapisati istim binarnim ciframa kao dati broj.
Koristiti bitovske operatore. Sa standarnog ulaza se unosi
broj, a na standarni izlaz se ispisuje rezultat. */

#include <stdio.h>

int main(){
 int x;
 scanf("%d", &x);
 
 unsigned int mask1=1;
 
 // pod a)
 unsigned int mask2 = 1 << ((sizeof(int)*8)-2);
 int y=0;
 while(mask1!=0){
  if(x&mask1){
   y=y|mask2;
   mask2 >>= 1;
  }
  mask1 <<= 1;
 }
 // pod b)
 unsigned int mask3=1;
 unsigned mask4=1;
 int z=0;
 while(mask4!=0){
  if(x&mask4){
   z=z|mask3;
   mask3 <<= 1;
  }
  mask4 <<= 1;
 } 
 
 printf("%d\n", y);
 printf("%d\n", z);
 
 return 0;
}

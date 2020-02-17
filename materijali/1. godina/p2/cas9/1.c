/* Napisati funkciju print_bits koja stampa bitove u zapisu
datog celog broja x. */

#include <stdio.h>

void print_bits(int x){
 unsigned n=sizeof(x)*8;
 unsigned maska=1<<(n-1); //00...01 -> 10...00
 while(maska){
  if(x&maska)
   putchar('1');
  else
   putchar('0');
  maska >>= 1;
 }
}

int main(){
 int x;
 scanf("%d", &x);
 
 print_bits(x);

 printf("\n"); 
 
 return 0;
}

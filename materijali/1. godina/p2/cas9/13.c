/* Napisati program koji ispisuje zapis datog broja u
pokretnom zarezu (napomena: moze se koristiti unija koja
sadrzi float i long). */

#include <stdio.h>

union broj{
 int ibroj;
 float fbroj;
};

void print_bits(int x){
 unsigned n=sizeof(x)*8;
 unsigned maska=1<<(n-1);
 while(maska){
  if(x&maska)
   putchar('1');
  else
   putchar('0');
  maska >>= 1;
 }
}

int main(){
 union broj x;
 scanf("%f", &x.fbroj);
 
 print_bits(x.ibroj);
 printf("\n");
 
 return 0;
}

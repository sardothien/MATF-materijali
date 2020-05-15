#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

unsigned invertuj(unsigned x){
 unsigned maska = 0; // maska = 00...00
 unsigned b = 4;     // b = 00...0100
 while(b>0){       
  maska = maska | b;  // maska = 00...0100 u 1. koraku
  b = b << 3;         // b = 00...0100000 u 1. koraku
 }
 return x | maska;  // x | 0100...0100100
}

int main(){
 unsigned x;
 scanf("%u", &x);
 
 printf("%u\n", invertuj(x));
 
 return 0;
}

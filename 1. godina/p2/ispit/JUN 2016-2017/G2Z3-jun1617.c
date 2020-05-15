#include <stdio.h>

unsigned izmena(unsigned x){
  unsigned maska = -1 << (8*sizeof(unsigned)-4);
  x = x ^ maska;
  x = x & -1 << 4;
  x = x | 9;
  return x;
}

int main(){
 unsigned x;
 scanf("%u", &x);
 
 printf("%u\n", izmena(x));
 
 return 0;
}

#include <stdio.h>
#include <stdlib.h>

unsigned izmena(unsigned x){
 unsigned maska = 7;  // 000...0111
 int pomeraj = 0;     // 000...0000
 while(pomeraj < 8*sizeof(unsigned)-3){  
  if(((x&maska)>>pomeraj) == 5) 
   x = x | maska;
  else if(((x&maska)>>pomeraj) == 2)
   x = x & ~maska;
  maska <<= 1;
  pomeraj++;
 }
 return x;
}

int main(){
 unsigned x;
 scanf("%u", &x);
 
 printf("%u\n", izmena(x));
 
 return 0;
}

#include <stdio.h>

int broj_jedinica(int x){
 unsigned maska = 1;
 int br = 0;
 while(maska){
  if(x & maska)
   br++;
  maska <<= 1;
 }
 return br;
}

unsigned izmena(int n, int m){
 unsigned maska = 1;
 unsigned br = 0;
 while(maska){
  if(((n & maska) != 0) && ((m & maska) == 0))
   br |= maska;
  maska <<= 1;
 }
 return br;
}

int main(){
 unsigned n, m;
 scanf("%u%u", &n, &m);
 
 if(broj_jedinica(n) > broj_jedinica(m))
  printf("%u\n", ~n);
 else 
  printf("%u\n", izmena(n, m));
 
 return 0;
}

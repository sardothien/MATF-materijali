#include <stdio.h>

int broj_pojavljivanja(unsigned n, unsigned m){
 unsigned maska = 15;
 unsigned poslednji = maska & m; 
 
 int br = 0, i = 0;
 while(i <= 8*sizeof(int)-4){
  if(((n & maska) >> i) == poslednji)
   br++;
  i++;
  maska <<= 1;
 }
 return br;
}

int main(){
 unsigned n, m;
 scanf("%u%u", &n, &m);
 
 printf("%d\n", broj_pojavljivanja(n, m));
 
 return 0;
}

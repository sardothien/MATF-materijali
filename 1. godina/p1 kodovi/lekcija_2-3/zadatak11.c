/* Napisati funkciju void ispis(float x, float y, unsigned n) koja za
dva realna broja x i y i jedan pozitivan ceo broj n ispisuje
vrednosti sinusne funkcije u n ravnomerno raspoređenih tačaka
intervala [x, y]. Napisati program koji učitava odgovarajuće
vrednosti i testira rad ove funkcije. */

#include <stdio.h>
#include <math.h>

void ispis(float x, float y, unsigned n){
 float i;
 float korak=(y-x)/(n-1);
 
 for(i=x; i<=y; i+=korak){
  printf("%.4f ", sin(i));
 }
 printf("\n");
}

int main(){
 
 float x, y;
 unsigned n;
 float t;
 scanf("%f%f%u", &x, &y, &n);
 
 if (n<=1 || x==y){
  printf("-1\n");
  return -1;
 }
 if (y<x){
  t=x;
  x=y;
  y=t;
 }

 ispis(x,y,n);
 
 return 0;
}

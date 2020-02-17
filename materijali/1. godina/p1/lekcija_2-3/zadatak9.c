/* Napisati funkciju int euklid(int x, int y) koja za dva
data cela broja određuje najveći zajednički delilac primenom
Euklidovog algoritma. Napisati program koji učitava dva cela broja i
ispisuje rezultat poziva funkcije. */

#include <stdio.h>

int euklid(int x, int y){
 int r;
 while(y){
  r=x%y;
  x=y;
  y=r;
 }
 
 return x;
}

int main(){
 
 int x, y;
 scanf("%d%d", &x, &y);
 
 printf("nzd je %d\n", euklid(x, y));
 
 return 0;
}

/* Napisati funkciju int min(int x, int y, int z) koja
izračunava minimum tri broja. Napisati program koji učitava tri cela broja i
ispisuje rezultat poziva funkcije. */

#include <stdio.h>

int min(int x, int y, int z){
 
 int m;
 
 m=x;
 if(m>y){
  m=y;
 }
 if(m>z){
  m=z;
 }
 
 return m;
}



int main(){

 int x, y, z, m;
 
 scanf("%d%d%d", &x, &y, &z);
 m=min(x, y, z);
 
 printf("%d\n", m); 
 
 return 0;
}

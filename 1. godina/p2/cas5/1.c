/* Napisati rekurzivnu funkciju koja prikazuje sve cifre
datog celog pozitivnog broja i to:
a) void ispis1(int x) - koja ispisuje s leva na desno;
b) void ispis2(int x) - koja ispisuje s desna na levo */

#include <stdio.h>
/* POD a) */
void ispis1(int x){
 if(x/10==0){
  printf("%d ", x);
  return;
 }
 
 ispis1(x/10);
 printf("%d ", x%10); 
}
/* POD b) */
void ispis2(int x){
 if(x/10==0){
  printf("%d ", x);
  return;
 }
 
 printf("%d ", x%10);
 ispis2(x/10);  
}

int main(){
 int n;
 scanf("%d", &n);
 
 ispis1(n);
 printf("\n");
 ispis2(n);
 printf("\n");
 
 return 0;
}

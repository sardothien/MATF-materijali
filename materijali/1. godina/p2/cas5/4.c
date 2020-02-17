/* Napisati rekurzivnu funkciju int ukloni(int x,
int c) koja uklanja sva pojavljivanja date cifre
c iz datog broja x. */

#include <stdio.h>

int ukloni(int x, int c){
 if(x/10==0)
  return x==c ? 0:x;
 
 int k=ukloni(x/10, c);
 if(x%10!=c)
  return k*10+x%10;
 else
  return k;
}

int main(){
 int n, c;
 scanf("%d%d", &n, &c);
  
 printf("Novi broj: %d\n", ukloni(n, c));
 
 return 0;
}

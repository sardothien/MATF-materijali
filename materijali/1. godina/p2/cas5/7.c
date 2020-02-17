/* Napisati rekurzivnu funkciju int obrni(int x, 
int p) koja obrce cifre datog celog broja x. */

#include <stdio.h>
#include <math.h>

int obrni(int x, int p){
 if(x<10) 
  return x;
 
 return (x%10)*pow(10,p)+obrni(x/10, p-1);
}

int duzina(int x){
 if(x/10==0)
  return 1;
 return 1+duzina(x/10);
}

int main(){
 int n;
 scanf("%d", &n);
 
 printf("Obrnuto: %d\n", obrni(n, duzina(n)-1));
 
 return 0;
}

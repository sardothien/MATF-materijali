/* Napisati rekurzivnu funkciju int dodaj 0(int x)
koja posle svake neparne cifre datog broja dodaje 0.
*/

#include <stdio.h>

int dodaj_0(int x){
 if(x==0)
  return 0;
 if(x%2==0)
  return dodaj_0(x/10)*10+x%10;
 else
  return (dodaj_0(x/10)*10+x%10)*10;
}

int main(){
 int n;
 scanf("%d", &n);
 
 printf("Novi broj: %d\n", dodaj_0(n));
 
 return 0;
}

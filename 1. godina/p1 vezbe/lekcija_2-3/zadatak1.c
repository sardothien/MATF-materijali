/* Napisati funkciju int kvadrat(int x) koja računa kvadrat
datog broja. Napisati program koji učitava ceo broj i ispuje rezultat poziva
funkcije. */

#include <stdio.h>

int kvadrat(int x){
  
 return x*x; 
}

int main(){

 int x;
 scanf("%d", &x);
 
 printf("%d\n", kvadrat(x));
 
 return 0;
}

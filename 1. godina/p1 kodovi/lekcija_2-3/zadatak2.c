/* Napisati funkciju int kub(int x) koja računa kub datog
broja. Napisati program koji učitava ceo broj i ispuje rezultat poziva funkcije. */

#include <stdio.h>

int kub(int x){

 return x*x*x;
}

int main(){
 
 int x;
 scanf("%d", &x);
 
 printf("%d\n", kub(x));
 
 return 0;
}

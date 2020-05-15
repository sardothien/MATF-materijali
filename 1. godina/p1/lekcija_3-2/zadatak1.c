/* Napisati funkciju koja uređuje svoja dva celobrojna argumenta tako
da se u prvom nalazi manji, a u drugom veći. Napisati program koji
učitava dva cela broja i ispisuje rezultat poziva funkcije. */

#include <stdio.h>

void uredi(int *a, int *b){
 int t;
 if(*a>*b){
  t=*a;
  *a=*b;
  *b=t;
 } 
}

int main(){
  
 int a, b;
 scanf("%d%d", &a, &b);
 
 uredi(&a, &b);
 printf("nakon uredi: a=%d, b=%d\n", a, b);
 
 return 0;
}

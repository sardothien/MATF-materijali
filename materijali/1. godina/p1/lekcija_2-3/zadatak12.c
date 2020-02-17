/* Napisati funkciju float aritmeticka_sredina(int n)
koja računa aritmetičku sredinu cifara datog broja. Napisati i program koji uči-
tava ceo broj i ispisuje rezultat na tri decimale. */

#include <stdio.h>
#include <stdlib.h>

float aritmeticka_sredina(int n){
 
 int s=0, br=0;
 n=abs(n); 
 
 while(n>0){
  s=s+n%10;
  br++;
  n=n/10;
 }
 
 return 1.0*s/br;
}

int main(){
 
 int n;
 scanf("%d", &n);
  
 printf("%.3f\n", aritmeticka_sredina(n));

 return 0;
}

/* Napisati funkciju int je_stepen(unsigned x, unsigned n) koja za
dva broja x i n utvrđuje da li je x neki stepen broja n. Ukoliko
jeste, funkcija vraća izložilac stepena, a u suprotnom vraća −1.
Napisati program koji učitava dva cela pozitivna broja i ispisuje
rezultat poziva funkcije. Napomena: Pretpostaviti da je unos korektan. */

#include <stdio.h>

int je_stepen(unsigned x, unsigned n){
 int i=1;
 int s=n;
 while(s<x){
  s=s*n;
  i++;
 }
 if(s==x){
  return i;
 }
 
 return -1;
}

int main(){
 
 unsigned x, n;
 int st;
 scanf("%u%u", &x, &n);
 
 if(x<0 || n<0){
  printf("-1\n");
  return -1;
 }
 
 st=je_stepen(x, n);
 if(st==-1){
  printf("Nije stepen broja %u\n", n);
 }
 else{
  printf("%u = %u^%d\n", x, n, st);
 }
 
 return 0;
}

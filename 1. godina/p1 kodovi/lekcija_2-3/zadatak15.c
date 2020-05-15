/* Napisati program za ispitivanje svojstava cifara datog celog
broja.
  a) Napisati funkciju sve_parne_cifre koja ispituje da li se dati
  ceo broj sastoji isključivo iz parnih cifara. Funkcija treba da
  vrati 1 ako su sve cifre broja parne i 0 u suprotnom.
  b) Napisati funkciju sve_cifre_jednake koja ispituje da li su sve
  cifre datog celog broja jednake. Funkcija treba da vrati 1 ako su 
  sve cifre broja jednake i 0 u suprotnom.
Napisati program koji učitava ceo broj i ispisuje da li su sve cifre
parne i da li su sve cifre jednake. */

#include <stdio.h>
#include <stdlib.h>

int sve_parne_cifre(int x){
 int d;
 x=abs(x);
 
 while(x>0){
  d=x%10;
  if(d%2==1){
   return 0;
  }
  x/=10;
 }
 
 return 1;
}


int sve_cifre_jednake(int x){
 int d, x1;
 x=abs(x);
 
 x1=x%10;
 x/=10;
 
 while(x){
  d=x%10;
  if(d!=x1){
   return 0;
  }
  x/=10;
 }
 
 return 1;
}


int main(){
 
 int x, d;
 scanf("%d", &x);
 
 if(sve_parne_cifre(x)){
  printf("Sve cifre parne.\n");
 }
 else{
  printf("Sve cifre nisu parne.\n");
 }
 if(sve_cifre_jednake(x)){
  printf("Sve cifre jednake.\n");
 }
 else{
  printf("Sve cifre nisu jednake.\n");
 }
  
 return 0;
}

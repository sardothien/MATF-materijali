/* Napisati funkciju int broj_neparnih_cifara(int x) koja određuje
broj neparnih cifara u zapisu datog celog broja. Testirati rad ove
funkcije u programu koji učitava cele brojeve dok se ne unese nula i
ispisuje broj neparnih cifara svakog unetog broja. */

#include <stdio.h>
#include <stdlib.h>

int broj_neparnih_cifara(int x){
 int b=0, i;
 x=abs(x);
 
 while(x){
  i=x%10;
  b+=(i%2);
  x/=10;
 }
 
 return b;
}

int main(){
 
 int x;
 
 do{
  scanf("%d", &x);
  printf("%d\n", broj_neparnih_cifara(x));
 } while (x!=0);
 
 return 0;
}

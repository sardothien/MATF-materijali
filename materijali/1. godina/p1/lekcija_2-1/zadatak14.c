/* Broj je Armstrongov ako je jednak zbiru kubova svojih cifara. Napisati program koji za dati trocifren broj proverava da li je Armstrongov. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
 
  int x;
  char c1, c10, c100;
  
  printf("Unesite trocifreni broj: ");
  scanf("%d", &x);
  
  x=abs(x);
  
  if(x<=99 || x>=1000){
    printf("Niste uneli trocifreni broj!\n");
    return -1;
  }
  
  c1=x%10;
  c10=(x/10)%10;
  c100=x/100;
 
 if(x==pow(c1,3)+pow(c10,3)+pow(c100,3)){
    printf("Broj je Amstrongov.\n");   
 }
  else{
   printf("Broj nije Amstrongov.\n");   
  }
 
  return 0;
}

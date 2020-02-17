/* Napisati program koji za pozitivan ceo broj proverava i ispisuje da li se cifra 5 nalazi u njegovom zapisu. */

#include <stdio.h>

int main() {

 int x, s=0;
 scanf("%d", &x);
 
 if(x<0){
  printf("-1\n");
  return -1;
 }
 
 while(x>0){
  if(x%10==5){
   s=1;
   break;
  }
  x=x/10;
 }
 
 if(s==1){
  printf("1\n");
 }  
 else{
  printf("0\n");
 }
   
 return 0;
}

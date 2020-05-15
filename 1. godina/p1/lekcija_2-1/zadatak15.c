/* Napisati program koji ispisuje proizvod parnih cifara unetog četvorocifrenog broja. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 
  int x, p=1;
  char c1, c10, c100, c1000;
  
  printf("Unesite cetvorocifreni broj: ");
  scanf("%d", &x);
  
  x=abs(x);
  
  if(x<1000 || x>9999){
    printf("Broj nije cetvorocifren!\n");
    return -1;
  }
  
  c1=x%10;
  c10=(x/10)%10;
  c100=(x/100)%10;
  c1000=x/1000;
 
 if(c1%2==0){
   p=p*c1;
 }
 if(c10%2==0){
   p=p*c10;
 }
 if(c100%2==0){
   p=p*c100;
 }
 if(c1000%2==0){
   p=p*c1000;
 }
 
 if(p!=1){
   printf("Proizvod parnih cifara: %d\n", p);
 }
  else{
    printf("Nema parnih cifara!\n");
  }
 
  return 0;
}

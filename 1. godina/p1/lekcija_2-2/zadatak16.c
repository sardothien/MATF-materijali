/* Napisati program koji učitava cele brojeve sve dok se ne unese nula. Nakon toga ispisati proizvod onih unetih brojeva koji su pozitivni. */

#include <stdio.h>

int main() {

 int x, p=1, ind=0;
 while(1){
  scanf("%d", &x);
  if(x==0){
  break;
  }
  if(x<0){
  continue;
  }  
  p=p*x;
  ind++;
 }
 
 if(ind>0){
  printf("%d\n", p);
 }
 else{
  printf("Nema pozitivnih brojeva.\n");
 }
   
 return 0;
}

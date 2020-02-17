/* Napisati program koji uneti prirodan broj transformiše tako što svaku parnu cifru u zapisu broja uveća za jedan. Ispisati novodobijeni broj. */

#include <stdio.h>

int main(){

 int x, y, p=1;
 
 scanf("%d", &x);
 if(x<0){
  printf("-1\n");
  return -1;
 }
 
 if(x==0){
  printf("%d\n", ++x);
  return 0;
 }
 
 y=x;
 while(x>0){
  if((x%10)%2==0){
   y=y+p;
  }
  p=p*10;
  x=x/10;
 }
 
 printf("%d\n", y);
 
 return 0;
}

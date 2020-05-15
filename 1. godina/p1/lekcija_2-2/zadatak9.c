/* Napisati program koji za uneti prirodan broj uklanja sve nule sa njegove desne strane. Ispisati novodobijeni broj. */

#include <stdio.h>

int main() {

 int x;
 
 scanf("%d", &x);
 
 if(x<0){
  printf("-1\n");
  return -1;
 }
 
 if(x==0){
  printf("%d\n", x);
 }
 
 while(x%10==0){
  x=x/10;
 }
 
 printf("%d\n", x);
 
 return 0;
}

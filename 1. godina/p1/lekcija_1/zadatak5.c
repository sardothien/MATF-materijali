/* Napisati program koji za unetu količinu jabuka u kilogramima i unetu cenu po kilogramu ispisuje ukupnu vrednost date količine jabuka. */

#include <stdio.h>
int main(){
  int a,b;
  
  printf("Unesite kolicinu jabuka (u kg): ");
  scanf("%d", &a);
 
  printf("Unesite cenu (u dinarima): ");
  scanf("%d", &b);
 
  printf("Molimo platite %d dinara\n", a*b);

  return 0;
}

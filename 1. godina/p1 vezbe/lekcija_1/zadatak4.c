/* Napisati program koji pomaže kasirki da izračuna ukupan račun ako su poznate cene dva kupljena artikla.  */

#include <stdio.h>
int main(){
  int a,b;
  
  printf("Unesi cenu prvog artikla: ");
  scanf("%d", &a);
  
  printf("Unesi cenu drugog artikla: ");
  scanf("%d", &b);

  printf("Ukupna cena iznosi: %d\n", a+b);

  return 0;
}

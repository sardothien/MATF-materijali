/* Napisati program koji ispisuje broj koji se dobija izbacivanjem cifre desetica u unetom prirodnom broju. */

#include <stdio.h>

int main() {
  
  int x;

  printf("Uneti broj: ");
  scanf("%d", &x);

  printf("Broj x bez cifre desetice: %d\n", x%10+(x/100)*10);

  return 0;
}

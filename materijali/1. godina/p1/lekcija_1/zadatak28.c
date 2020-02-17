/* Napisati program koji za unete pozitivne prirodne brojeve x, p i c ispisuje broj koji se dobija ubacivanjem cifre c u broj x na poziciju p. */

#include <stdio.h>
#include <math.h>

int main() {

  int x, p, c, s;
  
  printf("Unesi redom x, p i c: ");
  scanf("%d%d%d", &x, &p, &c);

  s=pow(10,p);
  printf("Rezultat je: %d\n", x%s+x/s*s*10+c*s); 

  return 0;
}

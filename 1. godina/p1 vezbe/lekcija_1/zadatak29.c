/* Napisati program koji za uneta dva cela broja a i b dodeljuje promenljivoj rezultat vrednost 1 ako važi uslov:
a) a i b su različiti brojevi
b) a i b su parni brojevi
c) a i b su pozitivni brojevi, ne veći od 100
U suprotnom, promenljivoj rezultat dodeliti vrednost 0. Ispisati vrednost promenljive rezultat. */

#include <stdio.h>
#include <math.h>

int main() {

  int a, b, rezultat;
  
  printf("Unesi 2 cela broja: ");
  scanf("%d%d", &a, &b);

  rezultat = a!=b ? 1 : 0;
  printf("a) Rezultat = %d\n", rezultat);

  rezultat = a%2 || b%2 ? 0 : 1;
  printf("b) Rezultat = %d\n", rezultat); 

  rezultat = a>0 && b>0 && a<=100 && b<=100 ? 1 : 0;
  printf("c) Rezultat = %d\n", rezultat);

  return 0;
}

/* Napisati program koji za uneta dva cela broja ispisuje njihov maksimum i minimum. */

#include <stdio.h>
#include <math.h>

int main() {

  int a, b;
  
  printf("Unesi 2 cela broja: ");
  scanf("%d%d", &a, &b);

  printf("a) max = %d\n", a>b ? a : b); 
  printf("b) min = %d\n", a<b ? a : b);

  return 0;
}

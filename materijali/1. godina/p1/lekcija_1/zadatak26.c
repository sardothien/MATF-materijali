/* Napisati program koji za tri uneta cela broja ispisuje njihovu artimetičku sredinu zaokruženu na dve decimale. */

#include <stdio.h>
#include <math.h>

int main() {

  int a, b, c;
  
  printf("Unesi 3 cela broja: ");
  scanf("%d%d%d", &a, &b, &c);

  printf("Aritmeticka sredina: %.2f\n", (float)(a+b+c)/3); 

  return 0;
}

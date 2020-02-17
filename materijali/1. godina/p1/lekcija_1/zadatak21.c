/* Napisati program koji za unete realne vrednosti dužina stranica pravougaonika ispisuje njegov obim i površinu. Ispisati tražene vrednosti zaokružene na dve decimale */

#include <stdio.h>

int main() {
 
  float a, b;

  printf("Unesi duzine stranica: ");
  scanf("%f%f", &a, &b);

  printf("Obim: %.2f\n", 2*a+2*b);
  printf("Povrsina: %.2f\n", a*b);

  return 0;
}

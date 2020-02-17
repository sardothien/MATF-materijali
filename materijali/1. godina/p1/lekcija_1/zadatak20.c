/* Napisati program koji za unete realne vrednosti a11, a12, a21, a22 ispisuje vrednost determinante matrice. Pri ispisu vrednost zaokružiti na 4 decimale. */

#include <stdio.h>

int main() {

  float a, b, c, d;
  
  printf("Uneti brojeve: ");
  scanf("%f%f%f%f", &a, &b, &c, &d);

  printf("Vrednost determinante: %.4f\n", a*d-b*c);

  return 0;
}

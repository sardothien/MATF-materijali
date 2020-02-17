/* Napisati program koji učitava težinu izraženu u funtama, konvertuje tu vrednost u kilograme i ispisuje je zaokruženu na dve decimale. */

#include <stdio.h>

int main() {

  float f;

  printf("Unesi broj funti: ");
  scanf("%f", &f);

  printf("%f mi = %.2f kg\n", f, f*0.45359237);

  return 0;
}

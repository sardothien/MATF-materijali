/* Napisati program koji učitava dužinu izraženu u miljama, konvertuje tu vrednost u kilometre i ispisuje je zaokruženu na dve decimale. */

#include <stdio.h>

int main() {

  float m;

  printf("Vrednost u miljama: ");
  scanf("%f", &m);

  printf("Vrednost u kilometrima: %.2f\n", m*1.609344);

  return 0;
}

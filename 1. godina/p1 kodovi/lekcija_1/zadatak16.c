/* Napisati program koji učitava realnu vrednost izraženu u inčima, konvertuje tu vrednost u centimetre i ispisuje je zaokruženu na dve decimale. */

#include <stdio.h>

int main() {

  float i;

  printf("Unesi vrednost u incima: ");
  scanf("%f", &i);

  printf("Vrednost u cm: %.2f\n", i*2.54);
  
  return 0;
}

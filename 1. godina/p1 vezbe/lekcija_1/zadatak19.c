/* Napisati program koji učitava temperaturu izraženu u farenhajtima, konvertuje tu vrednost u celzijuse i ispisuje je zaokruženu na dve decimale. */

#include <stdio.h>

int main() {

  float t;
  
  printf("Unesi temperaturu u F: ");
  scanf("%f", &t);

  printf("Temperatura u C: %.2f\n", (t-32)*5/9);

  return 0;
}

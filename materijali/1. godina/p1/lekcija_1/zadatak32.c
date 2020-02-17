/* Napisati program koji za unete realne vrednosti promenljivih x i y ispisuje vrednost izraza zaokruženu na dve decimale. */

#include <stdio.h>
#include <math.h>

int main() {

  float x, y;
  
  printf("Unesi 2 broja: ");
  scanf("%f%f", &x, &y);

  printf("Rezultat je = %.2f\n", ((x<y ? x : y)+0.5)/(1+pow(x<y ? y : x, 2))); 

  return 0;
}

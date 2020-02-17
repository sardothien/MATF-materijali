/* Napisati program koji za unete realne vrednosti dužina stranica trougla ispisuje njegov obim i površinu zaokružene na dve decimale. */

#include <stdio.h>
#include <math.h>

int main() {

  float a, b, c, s;
  

  printf("Duzine stranica trougla: ");
  scanf("%f%f%f", &a, &b, &c);

  s=(a+b+c)/2;

  printf("Obim: %.2f\n", a+b+c);
  printf("Povrsina: %.2f\n", sqrt(s*(s-a)*(s-b)*(s-c)));

  return 0;
}

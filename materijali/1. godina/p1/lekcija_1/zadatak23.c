/* Napisati program koji za unetu realnu vrednost dužine stranice jednakostraničnog trougla ispisuje njegov obim i površinu zaokružene na dve decimale. */

#include <stdio.h>
#include <math.h>

int main() {

  float a;

  printf("Unesi duzinu stranice trougla: ");
  scanf("%f", &a);

  printf("Obim: %.2f\n", a+a+a);
  printf("Povrsina: %.2f\n", pow(a,2)*sqrt(3)/4);

  return 0;
}

/* Napisati program koji za unetu realnu vrednost dužine poluprečnika kruga ispisuje njegov obim i površinu zaokružene na dve decimale. */

#include <stdio.h>

int main() {

  float r;

  printf("Vrednost poluprecnika kruga: ");
  scanf("%f", &r);

  printf("Obim: %.2f\n", 2*r*3.14);
  printf("Povrsina: %.2f\n", r*r*3.14);

  return 0;
}

/* Pravougaonik čije su stranice paralelne koordinatnim osama zadat je svojim realnim koordinatama suprotnih temena (gornje levo i donje desno teme). Napisati program koji ispisuje njegov obim i površinu zaokružene na dve decimale. */

#include <stdio.h>

int main() {

  float x_gl, y_gl, x_dd, y_dd;
  
  printf("Unesite koordinate gornjeg levog temena: ");
  scanf("%f%f", &x_gl, &y_gl);

  printf("Unesite koordinate donjeg desnog temena: ");
  scanf("%f%f", &x_dd, &y_dd);

  printf("Obim: %.2f\n", 2*(x_dd-x_gl)+2*(y_gl-y_dd));
  printf("Povrsina: %.2f\n", (x_dd-x_gl)*(y_gl-y_dd));  

  return 0;
}

/* Napisati program koji za uneta dva cela broja ispisuje najpre unete vrednosti, a zatim i njihov zbir, razliku, proizvod, ceo deo pri deljenju prvog broja drugim brojem i ostatak pri deljenju prvog broja drugim brojem. */

#include <stdio.h>
int main(){
  int a,b;
  
  printf("Prvi broj: ");
  scanf("%d", &a);

  printf("Drugi broj: ");
  scanf("%d", &b);

  printf("Zbir: %d\n", a+b);
  printf("Razlika: %d\n", a-b);
  printf("Proizvod: %d\n", a*b);
  printf("Ceo deo deljenja: %d\n", a/b);
  printf("Ostatak deljenja: %d\n", a%b);

  return 0;
}

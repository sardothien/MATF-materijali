/* Napisati program za uneti ceo broj ispisuje njegov kvadrat i njegov kub. */

#include <stdio.h>
int main(){
  int a;

  printf("Unesite ceo broj: ");
  scanf("%d", &a);

  printf("Kvadrat: %d\n", a*a);
  printf("Kub: %d\n", a*a*a);

 return 0;
}

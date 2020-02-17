/* Napisati program koji za dva uneta cela broja ispisuje njihov maksimum. */

#include <stdio.h>

int main(){

  int x, y;
  int max;

  printf("Uneti dva cela broja: ");
  scanf("%d%d", &x, &y);

  max = x;

  if(y > x){
      max = y;
  }
   
  printf("Maksimum je %d.\n", max);

  return 0;
}

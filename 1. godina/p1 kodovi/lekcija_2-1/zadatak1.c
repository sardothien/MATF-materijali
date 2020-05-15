/* Napisati program koji za dva uneta cela broja ispisuje njihov minimum. */

#include <stdio.h>

int main(){

  int x, y;
  int min;

  printf("Uneti dva cela broja: ");
  scanf("%d%d", &x, &y);

  min = x;

  if(y < x){
      min = y;
  }
   
  printf("Minimum je %d.\n", min);

  return 0;
}

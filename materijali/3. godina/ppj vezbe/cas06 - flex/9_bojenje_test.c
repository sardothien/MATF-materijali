#include <stdio.h>
#define P 0
#define N 1

  /* Glavni program */
int main()
{
  char c;
  int stanje = P;
  int prelaz[2][2] = { {N, P}, {P, N} };
  
  while ((c = getchar()) != EOF && c != '\n') {
    if (c != '0' && c != '1') {
      printf("Greska:%c.\n", c);
      return -1;
    }
    stanje = prelaz[stanje][c - '0'];
  }
  if (stanje == P)
    printf("Prepoznata parna rec.\n\\");
  else
    printf("Nije prepoznata parna rec.\n");
  return 0;
}

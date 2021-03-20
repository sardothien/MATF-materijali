#include <stdio.h>

int savrsen_stepen(unsigned n, unsigned *m, unsigned *k);

int main(){
 unsigned n;
 scanf("%u", &n);
 
 unsigned m, k;
 if(savrsen_stepen(n, &m, &k))
  printf("%u %u\n", m, k);
 else
  printf("Nije savrsen stepen.\n");
 
 return 0;
}
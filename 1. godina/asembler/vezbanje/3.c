#include <stdio.h>

unsigned min(unsigned, unsigned, unsigned);

int main(){
 unsigned a, b, c;
 scanf("%u%u%u", &a, &b, &c);
 
 printf("%d\n", min(a, b, c));
 
 return 0;
}

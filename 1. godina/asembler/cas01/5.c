#include <stdio.h>

int izraz(int a, int b, int c);

int main(){
 int a, b, c;
 scanf("%d%d%d", &a, &b, &c);
 
 printf("%d\n", izraz(a, b, c));
 
 return 0;
}

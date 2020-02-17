#include <stdio.h>

int izracunaj(int, int, int);

int main(){
 int a, b, n;
 scanf("%d%d%d", &n, &a, &b);
 
 printf("%d\n", izracunaj(n, a, b)); 
 
 return 0;
}

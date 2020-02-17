#include <stdio.h>

void deljenje(int a, int b, int *c, int *d);

int main(){
 int a, b, c, d;
 scanf("%d%d", &a, &b);
 
 deljenje(a, b, &c, &d);
 
 printf("%d %d\n", c, d);
 
 return 0;
}

#include <stdio.h>

int s_niz(int, int, int);

int main(){
 int a, b;
 scanf("%d%d", &a, &b);
 
 int n;
 scanf("%d", &n);
 
 printf("%d\n", s_niz(a, b, n)); 
 
 return 0;
}

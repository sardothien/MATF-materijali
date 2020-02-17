#include <stdio.h>

int proizvod(int a, int b);

int main(){
 int a, b;
 scanf("%d%d", &a, &b);
 
 printf("%d\n", proizvod(a, b));
 
 return 0;
}

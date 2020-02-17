#include <stdio.h>

int aritmetika(int, int, char);

int main(){
 int x, y;
 char c;
 scanf("%d%d %c", &x, &y, &c);
 
 printf("%d\n", aritmetika(x, y, c));
 
 return 0;
}

/* Date su dve celobrojne promenljive. Napisati program koji razmenjuje njihove vrednosti. */

#include <stdio.h>
int main(){
   int x,y;

   printf("Unesi dve celobrojne vrednosti: ");
   scanf("%d%d", &x, &y);

   printf("Pre zamene: x=%d, y=%d\n", x,y);
   printf("Posle zamene: x=%d, y=%d\n", y,x);

   return 0;
}

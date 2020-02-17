/* Napisati program koji učitava pozitivan trocifreni broj sa standardnog ulaza i ispisuje broj dobijen obrtanjem njegovih cifara. */

#include <stdio.h>
#include <stdlib.h> 
int main() {
   int x;

   printf("Unesi trocifreni broj: ");
   scanf("%d", &x);

   x = abs(x);
   
   printf("Obrnuto: %d\n", (x%10)*100 + ((x/10)%10)*10 + x/100);
   
   return 0;
}

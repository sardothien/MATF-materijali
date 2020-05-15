/* Date su dve celobrojene promenljive a i b. Napisati program koji promenljivoj a dodeljuje njihovu sumu, a promenljivoj b njihovu razliku. */

#include <stdio.h>
int main(){
   int a,b;

   printf("Unesi dve celobrojne vrednosti: ");
   scanf("%d%d", &a, &b);

   printf("Nove vrednosti su: a=%d, b=%d\n", a+b, a-b);

   return 0;
}

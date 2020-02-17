/* Napisati program koji za uneti pozitivan trocifreni broj na standardni izlaz ispisuje njegove cifre jedinica, desetica i stotina. */

#include <stdio.h>
int main(){
   int a;
  
   printf("Unesi broj: ");
   scanf("%d", &a);

   printf("Jedinice %d\n", a%10);
   a=a/10;
   printf("Desetice %d\n", a%10);
   a=a/10;
   printf("Stotine %d\n", a);

   return 0;
}

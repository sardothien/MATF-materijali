/* 2016/2017 - Predlog kolokvijuma GRUPA 2, zadatak 2 */
/* Napisati program koji za uneti pozitivan etvorocifreni broj, ako je uneti broj broj palindrom, ispisuje
broj koji se dobija izbacivanjem cifara sa parnih pozicija iz unetog broja, ili, ako uneti broj nije palin-
drom, ispisuje broj koji se dobija izbacivanjem cifara sa neparnih pozicija iz unetog broja. Pozicije se
broje sa desna na levo i poˇcinju od 0. U sluˇcaju greke, na standardni izlaz ispisati -1. */

#include <stdio.h>

int main() {

  int x, y;
  int c1, c10, c100, c1000;
 
  scanf("%d", &x);
  
  if(x<1000 || x>9999){
     printf("-1\n");
     return -1;
  }
  
  c1 = x%10;  /* cifra na poziciji 0 */
  c10 = (x/10)%10; /* cifra na poziciji 1 */
  c100 = (x/100)%10; /* cifra na poziciji 2 */
  c1000 = x/1000; /* cifra na poziciji 3 */
  
  if((c1==c1000) && (c10==c100)){
       y = c10 + c1000*10;
  }
   else{
       y = c1+c100*10;
   }
   
  printf("%d\n", y);  

  return 0;
}

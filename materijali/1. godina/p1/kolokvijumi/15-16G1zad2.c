/* 2015/2016 - Kolokvijum GRUPA 1, zadatak 2 */
/* Sa standardnog ulaza unose se jedan karakter (p ili n) i dva pozitivna trocifrena broja. Na osnovu
vrednosti unetog karaktera izracunati i ispisati na standardni izlaz:
p - zbir cifara na parnim pozicijama unetih brojeva
n - zbir cifara na neparnim pozicijama unetih brojeva
Cifre se broje sa desne strane, tako da cifri jedinice odgovara pozicija 1.
U slucaju greske (ukoliko karakter nije p ili n ili nisu uneti pozitivni trocifreni brojevi) ispisati -1. */

#include <stdio.h>

int main(){

 char c;
 int x, y, rez;
 int x1, x10, x100, y1, y10, y100;
 
 scanf("%c %d %d", &c, &x, &y);
 if(x<100 || x>999){
  printf("-1\n");
  return -1;
 }
 if(y<100 || y>999){
  printf("-1\n");
  return -1;
 }
 
 x1=x%10;
 x10=(x/10)%10;
 x100=x/100;
 y1=y%10;
 y10=(y/10)%10;
 y100=y/100;
  
 switch(c){
  case 'p': rez=x10+y10;
            break;
  case 'n': rez=x1+x100+y1+y100;
            break;
  default: printf("-1\n");
           return -1;
 }

 printf("%d\n", rez);
 
 return 0;
}

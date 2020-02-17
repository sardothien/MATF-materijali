/* 2015/2016 - Kolokvijum GRUPA 1, zadatak 3 */
/* Sa standardnog ulaza ucitava se pozitivan ceo broj i ceo broj i (1 ≤ i). Na standardni izlaz ispisati
broj koji se dobija kada se ukloni i-ta cifra broja. Cifre se broje sa desne strane, tako da cifri jedinice
odgovara pozicija 1. Neispravan ulaz je kada se unose negativan broj ili negativna vrednost ili nula za
i i u tom slucaju na standardni izlaz ispisati -1. Ukoliko broj nema i-tu cifru broj ostaje nepromenjen. */

#include <stdio.h>

int main(){

 int x, i, k, c=1, y, y1;
 
 scanf("%d%d", &x, &i);
 
 if(x<0){
  printf("-1\n");
  return -1;
 }
 if(i<1){
  printf("-1\n");
  return -1;
 }
 
 for(k=0; k<i; k++){
  c=c*10;
 }
 
 y=x%c;
 x=x/c;
 
 y1=y%(c/10);
 
 printf("%d\n", x*10+y1);

 return 0;
}

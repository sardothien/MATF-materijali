/* Nikola želi da obraduje baku i da joj kupi jedan poklon u radnji. On na raspolaganju ima m novaca. U radnji se nalazi n artikala i zanima ga koliko ima artikala u radnji čija cena je manja ili jednaka m. Napisati program koji pomaže Nikoli da brzo odrediti broj atikala. Program učitava realan pozitivan broj m, ceo pozitivan broj n i n realnih pozitivnih brojeva različitih od 0. Ispisati koliko artikala ima manju ili jednaku cenu od m. U slučaju greške ispisati odgovarajuću poruku. */

#include <stdio.h>

int main() {

 float m, x;
 int n, br=0;
 
 scanf("%f\n", &m);
 scanf("%d\n", &n);
 if(m<=0 || n<=0){
  printf("-1\n");
  return -1;
 }
 
 while(n>0){
  scanf("%f", &x);
  if(x<=m){
   br++;
  }
  if(x<=0){
  printf("-1\n");
  return -1;
 } 
  n--;
  }
  printf("%d\n", br);

 return 0;
}

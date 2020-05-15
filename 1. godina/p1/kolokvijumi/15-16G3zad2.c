/* 2015/2016 - Kolokvijum GRUPA 3, zadatak 2 */
/* Napisati C program koji sa standardnog ulaza ucitava 4 velika slova abedece i nenegativan ceo broj k. Program na standardni izlaz ispisuje 4 karaktera koji se dobijaju ciklickim pomeranjem (u okviru karakterske tabele) unetih karaktera za k mesta unapred. Na primer, karakter A pomeren za 4 mesta unapred postaje E dok karakter Z pomeren za 3 mesta unapred postaje C. U slucaju neispravnog ulaza ispisati -1. Ulaz se smatra neispravnim ako neki od unetih karaktera ne predstavlja veliko slovo abecede ili ako je broj k negativan, pretpostaviti da se na ulazu uvek zadaje tacno cetiri karaktera. */

#include <stdio.h>

int main(){

 char c1, c2, c3, c4, x1, x2, x3, x4;
 int k;
 
 scanf("%c%c%c%c %d", &c1, &c2, &c3, &c4, &k);
 
 if(k<0){
  printf("-1\n");
  return -1;
 }
 if(c1<'A' || c1>'Z' || c2<'A' || c2>'Z' || c3<'A' || c3>'Z' || c4<'A' || c4>'Z'){
  printf("-1\n");
  return -1;
 }
 
 if(c1+k>'Z'){
  x1='A'+(c1+k-'Z')%26-1;
 }
 else{
  x1=c1+k;
 }
 
 if(c2+k>'Z'){
  x2='A'+(c2+k-'Z')%26-1;
 }
 else{
  x2=c2+k;
 }
 
 if(c3+k>'Z'){
  x3='A'+(c3+k-'Z')%26-1;
 }
 else{
  x3=c3+k;
 }
 
 if(c4+k>'Z'){
  x4='A'+(c4+k-'Z')%26-1;
 }
 else{
  x4=c4+k;
 }

 printf("%c%c%c%c\n", x1, x2, x3, x4);



 return 0;
}

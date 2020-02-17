/* 2016/2017 - Predlog kolokvijuma GRUPA 1, zadatak 3 */
/* Napisati program koji za unetu registraciju, formata GGBBBB, gde je GG skracenica za grad i moze
imati vrednosti BG - Beograd, NS - Novi Sad, NI - Nis, SU - Subotica ili VA - Valjevo, a BBBB redni
broj, ispisuje puno ime grada i redni broj bez vodecih nula. U slucaju greke, na standardni izlaz ispisati
-1. */

#include <stdio.h>
#include <ctype.h>

int main(){

 char g1, g2, b1, b2, b3, b4;
 int broj;
 
 scanf("%c%c%c%c%c%c", &g1, &g2, &b1, &b2, &b3, &b4);
 
 /* Uslovi */
 if(!isdigit(b1) || !isdigit(b2) || !isdigit(b3) || !isdigit(b4)){
    printf("-1\n");
    return -1;
 }
 
 /* Gradovi */
 if(g1=='B' && g2=='G'){
  printf("Beograd ");
 }
 else if(g1=='N' && g2=='S'){
  printf("Novi Sad ");
 }
 else if(g1=='N' && g2=='I'){
  printf("Nis ");
 }
 else if(g1=='S' && g2=='U'){
  printf("Subotica ");
 }
 else if(g1=='V' && g2=='A'){
  printf("Valjevo ");
 }
 else{
  printf("-1\n");
  return -1;
 }
 
 /* Brojevi */
  if(isdigit(b1) && isdigit(b2) && isdigit(b3) && isdigit(b4)){
      broj=(b1-'0')*1000 + (b2-'0')*100  + (b3-'0')*10 + b4-'0';
      printf("%d\n", broj);
   }

 return 0;
}

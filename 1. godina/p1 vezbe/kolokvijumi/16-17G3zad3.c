/* 2016/2017 - Predlog kolokvijuma GRUPA 3, zadatak 3 */
/* Sa standardnog ulaza se ucitavaju pozitivan realan broj n i karakter k koji predstavlja mernu jedinicu za
vreme (s - sekund, d - minut, h - sat). Na standardni izlaz ispisati kojom brzinom se krece objekat ako
za zadatu vrednost vremena prelazi put od 10m. Rezultat izraziti u m/s i ispisati ga na cetiri decimale.
Brzina = predjeni put / vreme. U slucaju greke, na standardni izlaz ispisati -1. */

#include <stdio.h>

int main(){

 float n, rez;
 char k;
 
 scanf("%f %c", &n, &k);
 if(n<0){
  printf("-1\n");
  return -1;
 }
 
 switch(k){
  case 's': rez=10/n;
            break;
  case 'd': rez=10/(60*n);
            break;
  case 'h': rez=10/(3600*n);
            break;
  default: printf("-1\n");
           return -1;
 }
 
 printf("%.4f\n", rez);

 return 0;
}

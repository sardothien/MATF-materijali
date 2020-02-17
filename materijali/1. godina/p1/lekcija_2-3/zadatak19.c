/* Napisati funkciju int ukloni_stotine(int n) koja modifikuje zadati
broj tako što iz njegovog zapisa uklanja cifru stotina (ako postoji).
Napisati program koji za brojeve koji se unose sve do pojave broja 0
ispisuje odgovarajuće brojeve kojima je uklonjena cifra stotine. */

#include <stdio.h>
#include <stdlib.h>

int ukloni_stotine(int n){
 if(n>-100 && n<100){
  return n;
 }
 else{
  int znak = n<0 ? -1:1;
  n=abs(n);
  return znak*((n/1000)*100 + n%100);
 }
}

int main(){
 int n;
 
 do{
  scanf("%d", &n);
  printf("%d\n", ukloni_stotine(n));
 } while(n!=0);
  
 return 0;
}

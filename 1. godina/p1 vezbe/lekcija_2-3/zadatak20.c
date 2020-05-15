/* Napisati funkciju int rotacija(int n) koja rotira cifre
zadatog broja za jednu poziciju u levo. Napisati program koji za
brojeve koji se unose sve do pojave broja 0 ispisuje odgovarajuće
rotirane brojeve. */

#include <stdio.h>
#include <math.h>

int rotacija(int n){
 int broj, br=0, znak;
 znak = n<0 ? -1:1;
 n=abs(n);
 
 broj=n;
 if(n>-10 && n<10){
  return n;
 } 
 
 while(n>=10){
  n/=10;
  br++;
 }
 
 return znak*((broj%(int)pow(10, br))*10 + n);
}

int main(){
 
 int n;
 do{
  scanf("%d", &n);
  printf("%d\n", rotacija(n));
 } while(n!=0);
 
 return 0;
}

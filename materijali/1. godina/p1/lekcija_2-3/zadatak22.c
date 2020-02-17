/* Broj je prost ako je deljiv samo sa 1 i sa samim sobom. Napisati
funkciju int prost (int x) koja ispituje da li je dati ceo broj prost.
Funkcija treba da vrati 1 ako je broj prost i 0 u suprotnom. Napisati
program koji za uneti ceo broj n ispisuje prvih n prostih brojeva. */

#include <stdio.h>
#include <math.h>

int prost(int x){
 int i;
 
 if(x==2 || x==3){
  return 1;
 }
 if(x%2==0){
  return 0;
 }
 
 for(i=3; i<=sqrt(x); i+=2){
  if(x%i==0){
   return 0;
  }
 }
 
 return 1; 
}

int main(){
 
 int n;
 scanf("%d", &n);
 int i=1, j=0;

 while(j<n){
  if(prost(i)){
   printf("%d\n", i);
   j++;
  }
  i++;
 }
 
 return 0;
}

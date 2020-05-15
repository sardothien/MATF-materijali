/* Napisati funkciju void prosti_brojevi(int m) koja ispisuje sve proste brojeve manje od broja m. Napisati program koji učitava ceo broj veći od 1 i ispisati rezultat poziva funkcije. U slučaju pogrešnog unosa, ispisati poruku o grešci. */

#include <stdio.h>
#include <math.h>

int prost (int x){

  int i;
  if(x==2 || x==3){
    return 1;       
   }
  if(x%2==0){
    return 0;
  }  
  for(i=3; i<=sqrt(x);i+=2){
    if(x%i==0){
      return 0;
    }
  }      
 return 1;
}

int main(){

  int n, i=1, j=0;
  scanf("%d",&n);
 
  while(j<n){
    if (prost(i)){
       printf("%d\n", i);
       j++;               
     }
    i++;
  }
  
  return 0;
}

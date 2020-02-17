/* Sa standardnog ulaza se unosi jedna linija teksta. Napisati
program koji izračunava i ispisuje koliko puta se pojavilo
svako od slova engleskog alfabeta u unetom tekstu. Ne praviti
razliku između malih i velikih slova. */

#include <stdio.h>
#include <ctype.h>

#define MAX 26

int main(){
 char a[MAX];
 int i, x;
  
 for(i=0; i<MAX; i++){
  a[i]=0;
 }
  
 while((x=getchar()) != '\n'){
  if(isupper(x)){
   a[x-'A']++;
  }
  if(islower(x)){
   a[x-'a']++;
  }
 }
 
 for(i=0; i<MAX; i++){
  printf("%c: %d\n", i+'a', a[i]);
 }
 
 
 return 0;
}

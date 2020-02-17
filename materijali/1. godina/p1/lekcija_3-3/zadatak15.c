/* Napisati program koji učitava nisku cifara sa eventualnim
vodećim znakom i pretvara je u ceo broj. Napomena: Zadatak
realizovati bez korišćenja ugrađene funkcije atoi iz biblioteke
stdlib.h */

#include <stdio.h>
#include <ctype.h>

#define MAX 11

int znak_broja(char b[]){
 if(b[0]=='-'){
  return -1;
 }
 return 1;
}

int formiraj_broj(char b[]){
 int i, n=0;
 int znak = znak_broja(b);
 i=0;
 if(znak==-1){
  i=1;
 }
 for(; b[i]!='\0'; i++){
   if(isdigit(b[i])){
     n = n*10 + b[i] - '0';
   }
   else{
    break;
   }
 }
 n*=znak;
 return n;
}

int main(){

 char broj[MAX];
 int n;
 scanf("%s", broj);
       
 printf("%d\n", formiraj_broj(broj));

 return 0;
}

/* Napisati funkciju void ukloni_slova(char s[]) koja
iz niske s uklanja sva mala i sva velika slova.
Napisati program koji za učitanu nisku maksimalne
dužine 20 karaktera ispisuje odgovarajuću izmenjenu
nisku. */

#include <stdio.h>
#define MAX 20

void pomocna_funkcija(char s[], int i){
 int j;
 for(j=i; s[j]; j++){
  s[j]=s[j+1];
 }
}

void ukloni_slova(char s[]){
 int i;
 for(i=0; s[i]!='\0'; i++){
  if(isalpha(s[i])){
   pomocna_funkcija(s, i);
   i--;
  }
 }
}

int main(){
 char s[MAX];
 scanf("%s", s);
 
 ukloni_slova(s);
 printf("%s\n", s);
 return 0;
}

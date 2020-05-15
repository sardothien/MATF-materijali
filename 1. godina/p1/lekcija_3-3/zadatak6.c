/* Napisati funkciju int sadrzi_veliko(char s[])
koja proverava da li niska s sadrži veliko slovo.
Napisati program koji za učitanu nisku
maksimalne dužine 20 karaktera proverava da li
sadrži veliko slovo i ispisuje odgovarajuću poruku. */

#include <stdio.h>
#include <ctype.h>
#define MAX 21

int sadrzi_veliko(char s[]){
 int i;
 for(i=0; s[i]!='\0'; i++){
  if(s[i]>='A' && s[i]<='Z'){
   return 1;
  }
 }
 return 0;
}

int main(){
 char s[MAX];
 scanf("%s", s);
 
 printf("%d\n", sadrzi_veliko(s));
 return 0;
}

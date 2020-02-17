/* Napisati funkciju void modifikacija(char s[]) koja
modifikuje nisku s tako što u njoj svaki drugi
karakter zameni zvezdicom. Napisati program koji
testira rad napisane funkcije za učitanu nisku
maksimalne dužine 20 karaktera. */

#include <stdio.h>
#include <ctype.h>

#define MAX 21

void modifikacija(char s[]){
 int i;
 for(i=0; s[i]!='\0'; i++){
  if(i%2!=0){
   s[i]='*';
  }
 }
}

int main(){
 char s[MAX];
 scanf("%s", s);
 
 modifikacija(s);
 printf("%s\n", s);
 return 0;
}

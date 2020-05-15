/* Napisati funkciju void konvertuj(char s[]) koja menja
datu nisku s tako što u njoj mala slova zamenjuje odgovarajućim
velikim slovima, a velika slova zamenjuje odgovarajućim malim
slovima. Napisati program koji testira ovu funkciju za učitanu
nisku maksimalne dužine 10 karaktera */

#include <stdio.h>
#include <ctype.h>

void konvertuj(char s[]){
 int i;
 for(i=0; s[i]!='\0'; i++){
  if(s[i]>='a' && s[i]<='z'){
   s[i] = toupper(s[i]);
  }
  else if(s[i]>='A' && s[i]<='Z'){
   s[i] = tolower(s[i]);
  }
 }
}

int main(){
  
  char s[11];
  scanf("%s", s); 
  
  konvertuj(s);   
  printf("%s\n", s);
  
 return 0;
}

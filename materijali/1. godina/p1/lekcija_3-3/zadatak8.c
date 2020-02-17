/* Napisati funkciju void skrati(char s[]) koja uklanja beline sa
kraja date niske. Napisati program koji testira ovu funkciju za
učitanu liniju maksimalne dužine 100 karaktera. Prikazati učitanu
i izmenjenu nisku između zvezdica. */

#include <stdio.h>
#include <ctype.h>

int strlen_klon(char s[]){
 int i=0;
 while(s[i]){
  i++;
 }     
 return i;
}

void skrati(char s[]){
 int i;
 for(i=strlen_klon(s)-1; i>=0; i--){
  if (!isspace (s[i])){
   break;
  }
 }
 s[i+1]='\0';
}

int main(){
 
 char s[]="rep belina                           ";
 
 printf("*%s*\n", s);   
 skrati(s);
 printf("*%s*\n", s);  

 return 0;
}

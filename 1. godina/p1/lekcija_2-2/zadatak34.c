/* Napisati program koji učitava karaktere dok se ne unese karakter tačka, i ako je karakter malo slovo ispisuje odgovarajuće veliko, ako je karakter veliko slovo ispisuje odgovarajuće malo, a u suprotnom ispisuje isti karakter kao i uneti. */

#include <stdio.h>
#include <ctype.h>

int main(){

 char c;
 
 while((c=getchar()) != '.'){
  if(isupper(c)){
   putchar(tolower(c));  
  }
  else if(islower(c)){
   putchar(toupper(c)); 
  }
  else{
   putchar(c);
  }
 }
 putchar('\n');

 return 0;
}

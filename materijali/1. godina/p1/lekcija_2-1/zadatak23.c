/* Napisati program koji učitava karakter i:
a) ako je c malo slovo, ispisuje odgovarajuće veliko
b) ako je c veliko slovo, ispisuje odgovarajuće malo
c) ako je c cifra, ispisuje poruku cifra
d) u ostalim slučajevima, ispisuje karakter c između dve zvezdice. */

#include <stdio.h>
#include <ctype.h>

int main(){
  
  char c;
  
  printf("Unesite karakter: ");
  scanf("%c", &c); 
  
  if(islower(c)){
    printf("%c\n", toupper(c));
   } 
    else if(isupper(c)){
       printf("%c\n", tolower(c));
      }     
    else if(isdigit(c)){
      printf("cifra\n"); 
     }
   else{
      printf("*%c*\n", c);
     }
  
  return 0;
}

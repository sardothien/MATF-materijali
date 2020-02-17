/* Napisati program koji za učitani karakter ispisuje uneti karakter i njegov ASCII kod. Ukoliko je uneti karakter malo (veliko) slovo, ispisati i odgovarajuće veliko (malo) slovo i njegov ASCII kod. */

#include <stdio.h>

int main(){

 char c;
 
 printf("Unesite karakter: ");
 scanf("%c", &c);
 
 printf("Uneti karakter: %c, njegov ASCII kod: %d\n", c, c);
 
 if(c>='a' && c<='z'){
    printf("Odgovarajuce veliko slovo: %c, njegov ASCII kod: %d\n", c-32, c-32);
 }
 if(c>='A' && c<='Z'){
    printf("Odgovarajuce malo slovo: %c, njegov ASCII kod: %d\n", c+32, c+32);
 }
  
  return 0;
}

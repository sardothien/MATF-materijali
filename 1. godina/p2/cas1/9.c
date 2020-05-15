/* Uobicajena praksa na UNIX sistemima je da se argumenti
komandne linije dele na opcije i argumente u uzem smislu. Opcije
pocinju znakom ’-’ nakon cega obicno sledi jedan ili vise
karaktera koji oznacavaju koja je opcija u pitanju. Ovim se
najcesce upravlja funkcionisanjem programa i neke mogucnosti
se ukljucuju ili iskljucuju. Argumenti najcesce predstavljaju
opisne informacije poput na primer imena datoteka. Napisati
program koji ispisuje sve opcije koje su navedene u komandnoj
liniji. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
 int i, j;
 
 for(i=0; i<argc; i++){
  if(argv[i][0]=='-'){
   for(j=1; argv[i][j]; j++){
    printf("%c ", argv[i][j]);
   }
  }
 }
 
 printf("\n");
 
 return 0;
}

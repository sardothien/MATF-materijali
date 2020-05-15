/* Argumenti komadne linije su opcija (-m, -v ili -mv) i
rec. Ukoliko je opcija -m pretvoriti sva slova reci u
mala slova, ukoliko je opcija -v pretvoriti sva slova u
reci u velika slova, a ukoliko je opcija -mv pretvoriti
sva mala slova u velika, a sva velika slova u mala
slova. Ukoliko opcija nije zadata ili je netacno
navedena ispisati -1 na standardni izlaz za greske. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void mala_slova(char *s){
 int i;
 for(i=0; s[i]; i++){
  if(isupper(s[i])){
   s[i]=tolower(s[i]);
   printf("%c", s[i]);
  }
  else
   printf("%c", s[i]);
 }
}

void velika_slova(char *s){
 int i;
 for(i=0; s[i]; i++){
  if(islower(s[i])){
   s[i]=toupper(s[i]);
   printf("%c", s[i]);
  }
  else
   printf("%c", s[i]);
 }
}

void velika_mala_slova(char *s){
 int i;
 for(i=0; s[i]; i++){
  if(islower(s[i])){
   s[i]=toupper(s[i]);
   printf("%c", s[i]);
  }
  else if(isupper(s[i])){
   s[i]=tolower(s[i]);
   printf("%c", s[i]);
  }
  else
   printf("%c", s[i]);
 }
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 if(strcmp(argv[1], "-m")==0)
  mala_slova(argv[2]);
 else if(strcmp(argv[1], "-v")==0)
  velika_slova(argv[2]);
 else if(strcmp(argv[1], "-mv")==0)
  velika_mala_slova(argv[2]);
 else
  greska();
 
 printf("\n");
  
 return 0;
}

/* Napisati program koji za učitanu nisku s i karakter c ispituje
da li se c pojavljuje u niski s. Ako se pojavljuje, program treba
da ispiše indeks prvog pojavljivanja karaktera c u niski s, a u
suprotnom -1. Pretpostaviti da niska može da ima najviše 20 karaktera. */

#include <stdio.h>
#include <string.h>

#define MAXLEN 21

int sadrzi(char s[], char c){
 int i;
 for(i=0; s[i]; i++){
  if(s[i]==c){
   return i;
  }
 }
 return -1;
}

int main(){

 char s[MAXLEN+1];
 char c;
 int i;
 
 scanf("%s", s);
 getchar();
 c=getchar();

 i=sadrzi(s, c);
 if(i!= -1){
  printf("%d\n", i);
 }
 else{
  printf("-1\n");
 }

 return 0;
}

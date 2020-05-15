/* Napisati program koji vrši poređenje niski.
Napisati funkciju:
int poredjenje(char s1[], char s2[]) — vraća 1
ako su s1 i s2 jednake niske, a 0 u suprotnom;
Napisati program koji za učitane dve reči dužine
najviše 20 znakova ispituje da li su jednake, pri
čemu se zanemaruje razlika između velikih i malih
slova. */

#include <stdio.h>
#include <ctype.h>
#define MAX 21

int poredjenje(char s1[], char s2[]){
 int i, br=0;
 for(i=0; s1[i]!='\0' && s2[i]!='\0'; i++){
  if(s1[i]>='A' && s1[i]<='Z'){
   s1[i]=tolower(s1[i]);
  }
  if(s2[i]>='A' && s2[i]<='Z'){
   s2[i]=tolower(s2[i]);
  }
  if(s1[i]==s2[i]){
   br++;
  }
  else{
   return 0;
  }
 }
 return 1;
}

int main(){
 char s1[MAX], s2[MAX];
 scanf("%s", s1);
 getchar();
 scanf("%s", s2);
 
 printf("%d\n", poredjenje(s1, s2));
 return 0;
}

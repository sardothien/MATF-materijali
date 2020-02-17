/* Napisati funkciju int podniska(char s[], char t[])
koja proverava da li je niska t podniska niske s.
Napisati program koji učitava dve niske maksimalne
dužine 10 karaktera i testira rad napisane funkcije. */

#include <stdio.h>
#include <ctype.h>
#define MAX 11

int podniska(char s[], char t[]){
 int i, j, k;
 for(i=0; s[i]!='\0'; i++){
  for(j=0, k=i; t[j]!='\0'; j++, k++){
   if(s[k]!=t[j]){
    break;
   }
  }
  if(t[j]=='\0'){
   return 1;
  }
 }
 return 0;
}

int main(){
 char s[MAX], t[MAX];
 scanf("%s", s);
 getchar();
 scanf("%s", t);
 
 printf("%d\n", podniska(s, t));
 return 0;
}

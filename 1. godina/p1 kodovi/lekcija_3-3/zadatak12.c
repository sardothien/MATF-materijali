/* Napisati program koji za unetu reč maksimalne
dužine 20 karaktera formira rezultujuću reč tako što
unetu reč kopira 4 puta, pri čemu se između svaka dva
kopiranja umeće crtica. */

#include <stdio.h>
#include <string.h>
#define MAX 21

void strcpy_klon(char s[], char t[]){
  int i;
  for(i=0; s[i]!='\0'; i++){
    t[i]=s[i];
  }   
  t[i] = '\0';
}

int main(){
 char s[MAX];
 char t[4*MAX];
 scanf("%s", s);
 
 strcpy_klon(s, t);
 printf("%s", t);
 printf("-");
 printf("%s", t);
 printf("-");
 printf("%s", t);
 printf("-");
 printf("%s", t);
 
 printf("\n");
 
 return 0; 
}

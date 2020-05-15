/* Napisati funkciju
void dupliranje(char t[], char s[])
koja na osnovu niske s formira nisku t tako što
duplira svaki karakter niske s. Napisati program
koji učitava nisku maksimalne dužine 20 karaktera
i testira rad napisane funkcije. */

#include <stdio.h>
#define MAX 21

void dupliranje(char t[], char s[]){
 int i, k;
 for(i=0, k=0; s[i]; i++, k+=2){
  t[k]=s[i];
  t[k+1]=s[i];
 }
 t[k]='\0';
}

int main(){
 char s[MAX], t[2*MAX];
 scanf("%s", s);
 
 dupliranje(t, s);
 printf("%s\n", t);
 return 0;
}

/* Napisati funkciju
void kopiraj_n(char t[], char s[], int n) 
koja kopira najviše n karaktera niske s u nisku t.
Napisati program koji testira rad napisane
funkcije. Pretpostaviti da je maksimalna dužina
niske s 20 karaktera. */

#include <stdio.h>
#define MAX 21

void kopiraj_n(char t[], char s[], int n){
 int i;
 for(i=0; i<n; i++){
  t[i]=s[i];
 }
 t[i]='\0';
}

int main(){
 char s[MAX], t[MAX];
 int n;
 scanf("%s", s);
 scanf("%d", &n);
 
 kopiraj_n(t, s, n);
 printf("%s\n", t);
 
 return 0;
}

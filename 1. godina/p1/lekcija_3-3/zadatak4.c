/* Napisati program koji proverava da li se uneta
niska završava samoglasnikom. Napisati funkciju:
int samoglasnik_na_kraju(char s[]) — ispituje da
li se niska s završava samoglasnikom.
Pretpostaviti da je uneta niska maksimalne dužine 20
karaktera. */

#include <stdio.h>
#include <ctype.h>
#define MAX 21

int samoglasnik_na_kraju(char s[]){
 int i, br=0;
 for(i=0; s[i]!='\0'; i++){
  br++;
 }
 if(s[br-1]=='a' || s[br-1]=='e' || s[br-1]=='i' || s[br-1]=='o' || s[br-1]=='u' || s[br-1]=='A' || s[br-1]=='E' || s[br-1]=='I' || s[br-1]=='O' || s[br-1]=='U'){
  return 1;
 }
 else{
  return 0;
 }
}

int main(){
 char s[MAX];
 scanf("%s", s);
 
 printf("%d\n", samoglasnik_na_kraju(s));
 return 0; 
}

/* Napisati program koji sifrira unetu nisku tako sto svako
slovo zamenjuje sledecim slovom abecede, slova ’z’ i ’Z’
zamenjuje redom sa ’a’ i ’A’, a ostale karaktere ostavlja
nepromenjene. Pretpostaviti da uneta niska nije duža od 20
karaktera. */

#include <stdio.h>
#include <ctype.h>

#define MAXLEN 21

void sifriraj(char s[]){
 int i;
 for(i = 0; s[i]; i++){
   if(isupper(s[i])){
     s[i] = s[i] != 'Z' ? s[i] + 1 : 'A';
   }
   else if(islower(s[i])){
     s[i] = s[i] != 'z' ? s[i] + 1 : 'a'; 
   }
 }          
}

int main(){

 char s[MAXLEN + 1];
 scanf("%s", s);
    
 sifriraj(s);
 printf("%s\n", s);
    
 return 0;
}

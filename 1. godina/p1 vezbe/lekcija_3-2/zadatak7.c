/* Napisati funkciju void modifikacija(char* s, char* t, int* br_modifikacija)
koja na osnovu niske s formira nisku t tako što svako malo slovo zamanjuje velikim.
Broj izvršenih modifikacija se čuva u okviru argumenta br_modifikacija. Pretpostaviti
da niska s neće biti duža od 20 karaktera. Napisati program koji testira rad napisane
funkcije. */

#include <stdio.h>

#define MAX 21

void modifikacija(char *s, char *t, int *br_modifikacija){
 int i;
 for(i=0; s[i]; i++){
  if(s[i]>='a' && s[i]<='z'){
   t[i] = toupper(s[i]);
   (*br_modifikacija)++;
  }
  else{
   t[i] = s[i];
  }
 }
}

int main(){
 char s[MAX], t[MAX];
 int br_modifikacija = 0;

 scanf("%s", s);

 modifikacija(s, t, &br_modifikacija);

 printf("%s\n%d\n", t, br_modifikacija);

  return 0;
}

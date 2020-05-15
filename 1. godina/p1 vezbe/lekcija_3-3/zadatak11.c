/* Napisati program koji učitava nisku src i formira nisku dst
trostrukim nadovezivanjem niske src. Možemo pretpostaviti da
niska src sadrži najviše 30 karaktera. */

#include <stdio.h>
#include <string.h>

#define MAX 30

void strcpy_klon(char kopija[], char original[]){
  int i;
  for(i=0; original[i]; i++){
    kopija[i]=original[i];
  }    
  kopija[i] = '\0';
}

int main(){
 
 char src[MAX+1];
 char dst[3*MAX+1];
 scanf("%s", src);
  
 strcpy_klon(dst,src); 
 strcat(dst,src);
 strcat(dst,src);
 
 printf("%s\n", dst);

 return 0;
}

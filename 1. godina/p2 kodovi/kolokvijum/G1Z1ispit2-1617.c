/* Kao argumenti komandne linije se redom zadaju
pozitivan ceo broj p i niska s. Napisati program
koji u datoteku podniske.txt ispisuje redom sa
leva na desno sve podniske od s, duzine p . Na
primer, za p = 3 i nisku "program", potrebno je
ispisati "pro", "rog", "ogr", "gra", "ram". U
slučaju greške ispisati -1 na standardni izlaz za
greške. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 int p=atoi(argv[1]);
 if(p<=0)
  greska();
 
 FILE *out=fopen("podniske.txt", "w");
 if(out==NULL)
  greska();
 
 int l=strlen(argv[2]);
 if(p>l)
  return 0;
 
 int i, j;
 for(i=0; i<l-p+1 ;i++){
  for(j=0; j<p; j++){
   fprintf(out, "%c", argv[2][i+j]); 
  }
  fprintf(out, " ");
 }
  
 fclose(out);
 
 return 0;
}

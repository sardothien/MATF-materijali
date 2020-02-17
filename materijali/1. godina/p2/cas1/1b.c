/* Napisati program koji prepisuje datoteku ulaz.txt u 
datoteku izlaz.txt i to liniju po liniju. Pretpostaviti 
da je maksimalna duzina linije 80 karaktera. */

#include <stdio.h>
#include <stdlib.h>

int main(){
 FILE *in, *out;
 
 in=fopen("ulaz.txt", "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 out=fopen("izlaz.txt", "w");
 if(out==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 char linija[81];
 while(fgets(linija,80,in)){ /* 80 jer je bez '/0' */
  if(fputs(linija, out)==EOF){
   fclose(in);
   fclose(out);
   fprintf(stderr, "-1\n");
   exit(EXIT_FAILURE);
  }
 }
 
 fclose(in);
 fclose(out);
 
 return 0;
}

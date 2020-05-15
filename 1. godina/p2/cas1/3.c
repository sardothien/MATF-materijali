/* Sa standarnog ulaza ucitavaju se imena dve tekstualne datoteke
i jedan karakter. Napisati program koji prepisuje datoteku cije
se ime navodi kao prva niska u datoteku cije ime se navodi kao
druga niska. Ukoliko je ucitan karakter u, program prilikom
prepisivanja treba da zamenjuje sva mala slova velikim, a ukoliko
je ucitan karakter l sva velika slova se zamenjuju malim. U
slucaju greske na standardni izlaz za greske ispisati -1.
Maksimalna duzina naziva datoteka je 20 karaktera. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
 
 char ime1[21], ime2[21];
 char c;
 
 scanf("%s%s %c", ime1, ime2, &c);
 if(c!='u' && c!='l'){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 FILE *in, *out;
 
 in=fopen(ime1, "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 out=fopen(ime2, "w");
 if(out==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 char karakter;
 if(c=='u'){
  while((karakter=fgetc(in))!=EOF){
   fputc(toupper(karakter), out);
  }
 }
 else{
  while((karakter=fgetc(in))!=EOF){
   fputc(tolower(karakter), out);
  }
 }

 fclose(in);
 fclose(out);

 return 0;
}

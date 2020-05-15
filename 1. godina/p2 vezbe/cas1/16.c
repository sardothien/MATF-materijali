/* Napisati program koji za dve datoteke cija se
imena zadaju kao dve niske na standardnom
ulazu, radi sledece: za cifru u prvoj datoteci, u
drugu datoteku se upisuje 0, za slovo se upisuje
1, a za sve ostale karaktere se upisuje 2. U
slucaju greske na standardni izlaz za greske
ispisati -1. Maksimalna duzina naziva datoteka je
20 karaktera. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 21

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(){
 char ime1[MAX], ime2[MAX];
 
 scanf("%s%s", ime1, ime2);
 FILE *in, *out;
 in=fopen(ime1, "r");
 out=fopen(ime2, "w");
 if(in==NULL || out==NULL)
  greska();
 
 char c;
 while((c=fgetc(in))!=EOF){
  if(isdigit(c)){
   fprintf(out, "0");
  }
  else if(isalpha(c)){
   fprintf(out, "1");
  }
  else{
   fprintf(out, "2");
  }
 }
 
 fclose(in);
 fclose(out);
 
 return 0;
}

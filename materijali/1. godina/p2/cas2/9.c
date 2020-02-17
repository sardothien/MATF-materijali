/* Ime datoteke dato je kao argument komandne linije.
U datoteci se nalaze otvorene i zatvorene zagrade i
jos nekakav tekst. Napisati program koji proverava da
li su zagrade pravilno uparene. Npr. ab( cd) ..
odgovor je jesu, a ..)ba() odgovor je nisu. U slucaju
greske na standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc!=2)
  greska();
 
 FILE *in=fopen(argv[1], "r");
 if(in==NULL)
  greska();
 
 char c;
 int otvorena=0;
 int zatvorena=0;
 while((c=fgetc(in))!=EOF){
  if(c=='(')
   otvorena++;
  else if(c==')')
   zatvorena++;
  if(otvorena-zatvorena<0){
   fclose(in);
   printf("nisu\n");
   exit(EXIT_FAILURE);
  }
 }
 
 if(otvorena-zatvorena!=0){
  fclose(in);
  printf("nisu\n");
  exit(EXIT_FAILURE);
 }
 else
  printf("jesu\n");
 
 fclose(in);
 
 return 0;
}

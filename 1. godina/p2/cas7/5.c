/* Napisati funkciju void svaka_n_ta(char* ime, int n)
koja prima ime datoteke i ceo broj n i na standardni
izlaz ispisuje svaku n-tu rec iz datoteke. Napisati
program koji testira napisanu funkciju. Ime datoteke i
broj n se zadaju kao argumenti komandne linije. U
slucaju greske na standardni izlaz za greske ispisati
-1. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void svaka_n_ta(char* ime, int n){
 int i=0;
 char *rec;
 while(fscanf(ime, "%s", rec)!=EOF){
  if(i%n==0)
   printf("%s ", rec);
  i++;
 }
 
}

int main(int argc, char *argv[]){
 if(argc!=3)
  greska();
 
 FILE *in=fopen(argv[1], "r");
 if(in==NULL)
  greska();
 
 
 int n=atoi(argv[2]);
 if(n<=0)
  greska();
  
 svaka_n_ta(argv[1], n);
 printf("\n");
 
 fclose(in);
  
 return 0;
}

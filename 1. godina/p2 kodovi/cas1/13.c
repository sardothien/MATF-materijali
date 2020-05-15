/* Sastaviti program koji sa standarnog ulaza
ucitava imena dve datoteke (ulazna i izlazna 
datoteka) i iz ulazne datoteke kopira u izlaznu
svaki drugi karakter polazeci od prvog procitanog
karaktera. U slucaju greske na standardni izlaz za
greske ispisati -1. Maksimalna duzina naziva
datoteka je 20 karaktera. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 21

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(){ 
 char naziv1[MAX], naziv2[MAX];
 scanf("%s %s", naziv1, naziv2);
 
 FILE *in, *out;
 in=fopen(naziv1, "r");
 out=fopen(naziv2, "w");
 if(in==NULL || out==NULL)
  greska();
 
 int i=0;
 char c;
 while(fscanf(in, "%c", &c)==1){
  if(i%2==1){
   fprintf(out, "%c", c);
  }
  i++;
 } 
 
 fclose(in);
 fclose(out);
 
 return 0;
}

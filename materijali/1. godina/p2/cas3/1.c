/* Napisati program koji filtrira datoteku imena.txt tako
sto na standardni izlaz ispisuje samo imena i prezimena.
Maksimalna duzina imena, kao i prezimena je 50 karaktera. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 51

int main(){
 FILE *in=fopen("imena.txt", "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int i;
 char ime[MAX], prezime[MAX];
 float prosek;
 
 while(1){
  fscanf(in, "%d. %s %s %f", &i, ime, prezime, &prosek);
  if(feof(in)){
   break;
  }
  fprintf(stdout, "%s %s\n", ime, prezime);
 }
 
 fclose(in); 
 
 return 0;
}

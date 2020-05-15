/* Napisati program koji prepisuje datoteku ulaz.txt u 
datoteku izlaz.txt i to karakter po karakter */

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
 
 char c;
 while(fscanf(in, "%c", &c)==1){
  fprintf(out, "%c", c);
 }
 
 fclose(in);
 fclose(out);
 
 return 0;
}

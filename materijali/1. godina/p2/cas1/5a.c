/* U datoteci cije se ime navodi na standarnom ulazu programa
nalazi se broj n, a zatim i n reci (duzine najvise 50 karaktera).
Napisati program koji ucitava ovaj niz i ispisuje ga na
standardni izlaz. U slucaju greske na standardni izlaz za greske
ispisati -1. Maksimalna duzina naziva datoteka je 20 karaktera.
Maksimalan broj reci je 256. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 char ime[21];
 char niz_reci[256][51];
 
 scanf("%s", ime);
 FILE *in; 
 in=fopen(ime, "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int n;
 fscanf(in, "%d", &n);
 if(n<0 || n>256){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int i;
 for(i=0; i<n; i++){
  fscanf(in, "%s", niz_reci[i]);
  printf("%s ", niz_reci[i]);
 }
 
 FILE *out;
 out=fopen("rez.txt", "w");
 if(out==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int k, ind=0;
 for(i=0; i<n; i++){
  ind=0;
  for(k=0; k<i; k++){
   if(strcmp(niz_reci[k], niz_reci[i])==0){
    ind=1;
    break;
   }
  }
  if(!ind){
   fprintf(out, "%s\n", niz_reci[i]);
  }
 }
 
 fclose(in);
 fclose(out);
 
 return 0;
}

/* U datoteci cije se ime navodi na standarnom ulazu programa
nalazi se broj n, a zatim i n reci (duzine najvise 50 karaktera).
Napisati program koji ucitava reci i ispisuje ih na standardni
izlaz; u datoteku rez.txt upisuje sve reci koje sadrze prvu rec i
podvlaku. U slucaju greske na standardni izlaz za greske ispisati
-1. Maksimalna duzina naziva datoteka je 20 karaktera. NAPOMENA:
Nije potrebno koristiti niz za cuvanje svih ucitanih reci. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 char ime[21];
 char rec[51], prva_rec[51];
 
 scanf("%s", ime);
 
 FILE *in, *out;
 in=fopen(ime, "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 out=fopen("rez.txt", "w");
 if(out==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 int n, i;
 fscanf(in, "%d", &n);
 fscanf(in, "%s", prva_rec);
 
 for(i=1; i<n; i++){
  fscanf(in, "%s", rec);
  if(strstr(rec, prva_rec)!=NULL && strchr(rec, '_')!=NULL){
   fprintf(out, "%s\n", rec);
  }
 }
 
 fclose(in);
 fclose(out);
 
 return 0;
}

/* U datoteci cije se ime navodi na standarnom ulazu programa
nalazi se broj n, a zatim i n reci (duzine najvise 50 karaktera).
Napisati program koji ucitava ovaj niz i iz njega uklanja sve
duplikate i u datoteku rez.txt ispisuje transformisani niz. U
slucaju greske na standardni izlaz za greske ispisati -1.
Maksimalna duzina naziva datoteka je 20 karaktera. Maksimalan
broj reci je 256. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
 char u[21], rec[51], reci[256][51];
 int i=0, j=0, id=0, n, br=0;
 
 scanf("%s", u);
 
 FILE *in, *out; 
 in=fopen(u, "r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 out=fopen("rez.txt", "w");
 if(out==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 fscanf(in, "%d", &n);
 
 while(i<n){
  fscanf(in, "%s ", rec);
  printf("%s ", rec);
  j=0;
  id=0;
  while(j<br){
   if(strcmp(rec, reci[j])==0){
    id=1;
    break;
   }
   j++;
  }
  if(id==0){
   fprintf(out, "%s ", rec);
   strcpy(reci[br++], rec);
  }
  i++;
 }
 
 fclose(in);
 fclose(out);
 
 return 0;

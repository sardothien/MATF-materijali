/* NE RADI
U datoteci ”r.txt” nalazi se broj n, za kojim sledi
n reci (n≥0, maksimalna duzina reci je 50 karaktera).
U datoteku ”b.txt” ispisati sve reci koje predstavljaju
cele brojeve u dekadnom zapisu, a u datoteku ”o.txt”
sve one koje to nisu. U slucaju greske ispisati −1 na
standardni izlaz. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 51

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(){
 FILE *in, *b, *o;
 in=fopen("r.txt", "r");
 b=fopen("b.txt", "w");
 o=fopen("o.txt", "w");
 if(in==NULL || b==NULL || o==NULL)
  greska();
 
 int n;
 char rec[MAX];
 fscanf(in, "%d", &n);
 if(n<=0)
  greska();
  
 int i, l=strlen(rec), br=0, br2=0, j;
 char c;
 for(i=0; i<n; i++){
  fscanf(in, "%s", rec);
  for(j=0; j<l; j++){
   if(isalpha(c=fgetc(in)))
    br++;
   else if(isdigit(c=fgetc(in)))
    br2++;
  }
  if(br==l)
   fprintf(o, "%s ", rec);
  if(br2==l)
   fprintf(b, "%s ", rec);
 }
 
 fclose(in);
 fclose(b);
 fclose(o); 
 
 return 0;
}

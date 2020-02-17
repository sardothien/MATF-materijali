/* U datoteci ”u1.txt” nalazi se broj n1 , za kojim
sledi n1 reci, dok se u datoteci ”u2.txt” nalazi broj n2,
za kojim sledi n2 reci (n1≥0, n2≥0, maksimalna duzina
reci je 50 karaktera). U datoteku ”i.txt” upisati
naizmenicno reci iz prve dve datoteke. U slucaju greske
ispisati −1 na standardni izlaz. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 51

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(){
 FILE *u1, *u2, *izlaz;
 u1=fopen("u1.txt", "r");
 u2=fopen("u2.txt", "r");
 izlaz=fopen("i.txt", "w");
 if(u1==NULL || u2==NULL || izlaz==NULL)
  greska();
 
 int n1, n2;
 char rec1[MAX], rec2[MAX];
 int i;
 fscanf(u1, "%d", &n1);
 fscanf(u2, "%d", &n2);
 if(n1<0 || n2<0)
  greska();
  
 for(i=1; i<=n1 || i<=n2; i++){
  fscanf(u1, "%s", rec1);
  fscanf(u2, "%s", rec2);
  fprintf(izlaz, "%s %s ", rec1, rec2);
 }
 

 fclose(u1);
 fclose(u2);
 fclose(izlaz);
 
 return 0;
}

/* Napisati program koji za uneto n, formira fajlove
1.txt, 2.txt,..., n.txt i popunjava ih na sledeci
nacin: U 1.txt smesta cele brojeve [0,n] sa korakom 1
(0,1,...,n). U 2.txt smesta cele brojeve [0,n] sa
korakom 2 (0,2,4,...) ... U n.txt smesta cele brojeve
[0,n] sa korakom n (0 i n). Maksimalna duzina imena
fajla je 50 karaktera. Vrednost promenljive n mora biti
u opsegu [0,100]. U slucaju greske na standardni izlaz
za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#define MAX 51

int main(){
 int n, i;
 char ime[MAX];
 
 scanf("%d", &n);
 if(n<1 || n>100){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }

 for(i=1; i<=n; i++){
  sprintf(ime, "%d.txt", i);
  FILE *out=fopen(ime, "w");
  if(out==NULL){
   fprintf(stderr, "-1\n");
   exit(EXIT_FAILURE);
  }
  int j;
  for(j=0; j<=n; j+=i){
   fprintf(out, "%d ", j);
  }
  printf("\n");
  fclose(out);
 }
 
 return 0;
}

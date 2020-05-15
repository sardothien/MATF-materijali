/* Sa standarnog ulaza se ucitava prirodan broj k
i ime datoteke u kojoj se prvo nalazi prirodan broj
n a zatim i n celih brojeva. Napisati program koji
prebrojava koliko k-tocifrenih brojeva postoji u
datoteci. U slucaju greske na standardni izlaz za
greske ispisati -1. Pretpostaviti da je sadrzaj
datoteke ispravan. Maksimalna duzina naziva
datoteka je 20 karaktera. */

#include <stdio.h>
#include <stdlib.h>

#define MAX 21

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(){
 
 int k, n, b, br=0, m=0;
 scanf("%d", &k);
 if(k<0)
  greska();
 
 char ime[MAX];
 scanf("%s", ime);
 FILE *in;
 in=fopen(ime, "r");
 if(in==NULL)
  greska();
 
 fscanf(in, "%d", &n);
 int i;
 for(i=0; i<n; i++){
  fscanf(in, "%d", &b);
  b=abs(b);
  br=0;
  while(b){
   b/=10;
   br++;
  }
  if(br==k)
   m++;
 }
 
 fclose(in); 
 printf("%d\n", m);
 
 return 0;
}

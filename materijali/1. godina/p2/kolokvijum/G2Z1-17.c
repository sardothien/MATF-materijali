/*Kao argumenti komandne linije se zadaju celi brojevi
a i b, broj n i naziv datoteke u kojoj se nalazi n realnih
brojeva. Napisati program koji u datoteku izlaz.txt upisuje
koliko ima brojeva u ulaznoj datoteci za koje važi da su
veci od zbira kvadrata brojeva a i b. U slučaju greške na
standardni izlaz za greške ispisati -1. Pretpostaviti
da je sadržaj datoteke ispravan. Maksimalna dužina
naziva datoteke je 20 karaktera. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc!=5)
  greska();
 
 int a, b;
 int n;
 a=atoi(argv[1]);
 b=atoi(argv[2]);
 n=atoi(argv[3]);
 if(n<=0)
  greska();
  
 int l=strlen(argv[4]);
 if(l>21)
  greska();
  
 FILE *in=fopen(argv[4], "r");
 FILE *out=fopen("izlaz.txt", "w");
 if(in==NULL || out==NULL)
  greska();
 
 int i;
 int br=0;
 float broj;
 for(i=0; i<n; i++){
  fscanf(in, "%f", &broj);
  if(broj > (a*a+b*b)){
   br++;
  }
 }
 
 fprintf(out, "%d", br);
  
 fclose(in);
 fclose(out);
 
 return 0;
}

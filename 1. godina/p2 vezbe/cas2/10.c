/* a) Napisati C funkciju int unesiSkup(char **s,
FILE* f) kojom se unosi skup elemenata iz datoteke
F. Skup se predstavlja kao niz karaktera, pri cemu su
dozvoljeni elementi skupa mala i velika slova
abecede, kao i cifre. Unos se prekida kada se naidje
na znak za novi red ili nedozvoljeni karakter za skup.
Maksimalan broj elemenata skupa nije poznat. Funkcija
vraca broj elemenata skupa koji su uspesno ucitani.
   b) Napisati funkciju void prebroj(char *s, int
*br_slova,int *br_cifara) kojom se odresjuje broj
slovnih elemenata skupa (velikih ili malih slova) kao
i broj cifara u skupu.
   c) Napisati glavni program gde se unose podaci o
skupu elemenata. Ime datoteke se zadaje kao argument
komandne linije. Na stadardni izlaz ispisati
informacije o broju slova i cifara (koristiti
funkcije pod a) i b)). U slucaju greske na standardni
izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

char unesiSkup(char **s, FILE* f){
 int n=0;
 char ch;
 f=fopen(s[1], "r");
 if(f==NULL){
  fclose(f);
  greska();
 }
 while((ch=fgetc(f))!=EOF){
  if((isupper(ch)) || (islower(ch)) || (isdigit(ch)))
   n++;
  else
   break;
 } 
 return n;
}

void prebroj(char *s, int *br_slova, int *br_cifara){
 int i;
 *br_slova=0;
 *br_cifara=0;
 for(i=0; s[i]; i++){
  if(isalpha(s[i]))
   (*br_slova)++;
  if(isdigit(s[i]))
   (*br_cifara)++;
 }
}

int main(int argc, char **argv){
 if(argc!=2)
  greska();
  
 FILE *f=fopen(argv[1],"r");
 if(f==NULL)
  greska();
 		
 char *s; 
 int br_slova, br_cifara;
 int n, i;
	
 n=unesiSkup(argv, f);
 s=(char*)malloc(n*sizeof(char));
 if(s==NULL){
  free(s);
  greska();
 }
  
 for(i=0; i<n; i++){
  fscanf(f, "%c", &s[i]);
 }

 s[i]='\0';
 prebroj(s, &br_slova, &br_cifara);
 fprintf(stdout, "broj slova: %d \nbroj cifara: %d\n", br_slova, br_cifara);


 return 0;
}

/* Definisati strukturu:
typedef struct{
unsigned int a, b;
char ime[5];
} PRAVOUGAONIK;
kojom se opisuje pravougaonik duzinama svojih 
stranica i imenom. Napisati program koji iz datoteke
cije ime se zadaje kao argument komandne linije ucitava
pravougaonike (nepoznato koliko), a zatim prvo ispisuje 
imena onih pravougaonika koji su kvadrati, a nakon toga
ispisuje vrednost najvece povrsine medju pravougaonicima
koji nisu kvadrati. U slucaju greske na standardni izlaz
za greske ispisati -1. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
 unsigned int a, b;
 char ime[5];
}PRAVOUGAONIK;

int main(int argc, char *argv[]){
 if(argc!=2){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 unsigned max_p=0;
 PRAVOUGAONIK p;
 
 FILE *in=fopen(argv[1],"r");
 if(in==NULL){
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
 }
 
 while(fscanf(in, "%u%u%s", &p.a, &p.b, p.ime)==3){
  if(p.a==0 || p.b==0){
   fprintf(stderr, "-1\n");
   exit(EXIT_FAILURE);
  }
  if(p.a==p.b){
   printf("%s ", p.ime);
  }
  else{
   if(p.a*p.b > max_p){
    max_p = p.a*p.b;
   }
  }
 }
 
 if(max_p!=0){
  printf("%u\n", max_p);
 }
 else{
  printf("\n");
 }
 
 fclose(in); 
 
 return 0;
}

/* Kao argumenti komandne linije zadaju se dva realna
broja a i b, (a ≤ b). Sa standardnog ulaza se zadaje 11
brojeva tipa float (redom a0,a1,...,a10) koji predstavljaju
koeficijente polinoma a10x10+a9x9+...+a1x+a0. Napisati
funkciju koja trazi nulu ovog polinoma na intervalu [a,b].
Pretpostaviti da ce na datom intervalu uvek postojati
tacno jedna nula. Rezultat ispisati na standardni izlaz,
zaokruzen na dve decimale. U slucaju greske na standardni
izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

float vrednost(float *c, float x){
 float rez=0;
 int i;
 for(i=11-1; i>=0; i--)
  rez=rez*x+c[i];
 return rez;
}

float nula(float *c, float levo, float desno){
 if(levo>desno)
  greska();
 
 float sr=levo+(desno-levo)/2;
 float vr=vrednost(c, sr);
 if(fabs(vr)<0.0001)
  return sr;
 else{
  float levi_kraj=vrednost(c, levo);
  if(vr*levi_kraj<0)
   return nula(c, levo, sr); 
  else
   return nula(c, sr, desno);
 }
}


int main(int argc, char* argv[]){
 if(argc!=3)
  greska();
  
 int a=atoi(argv[1]);
 int b=atoi(argv[2]);
 if(a>b)
  greska();
 
 
 int n=11;
 float broj[11];
 int i;
 for(i=0; i<n; i++)
  scanf("%f", &broj[i]);
 
 printf("%.2f\n", nula(broj, a, b));
 
 return 0;
}

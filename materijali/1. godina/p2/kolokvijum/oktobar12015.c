/* Uz pomoc argumenata komandne linije zadat je niz
trouglova. Svaki trougao je zadat sa tri broja tipa 
float koji predstavljaju duzine njegovih stranica.
Ispisati povrsinu trougla koji ima najvecu povrsinu na
standardni izlaz zaokruzenu na 2 decimale. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if((argc-1)%3!=0)
  greska();
 if(argc==1){
  printf("0.00\n");
  return 0;
 } 
 
 float max=0;
 int i;
 for(i=1; i<argc; ){
  float a=atof(argv[i]);
  i++;
  float b=atof(argv[i]);
  i++;
  float c=atof(argv[i]);
  i++;
  float s=(a+b+c)/2;
  float P=sqrtf(s*(s-a)*(s-b)*(s-c));
  if(P>max)
   max=P;
 }
 
 printf("%.2f\n", max); 
 
 return 0;
}

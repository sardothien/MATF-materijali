/* Kao argumenti komandne linije zadaju se celi
brojevi. Na standardni izlaz ispisati:
• zbir unetih brojeva, ako su brojevi zadati u strogo
  rastućem poretku
• 0, ako su svi brojevi jednaki
• proizvod unetih brojeva, ako su zadati u strogo
  opadajućem poretku
• karakter '-' ako nijedan uslov nije ispunjen.
Brojevi mogu biti negativni. U slučaju da nije zadat ni
jedan broj, ispisati -1 na standardni izlaz za greške.*/

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc==1)
  greska();
 
 int jednaki=1;
 int rastuce=1;
 int opadajuce=1;
 int suma=atoi(argv[1]);
 int proizvod=atoi(argv[1]);
 
 int i;
 for(i=2; i<argc; i++){
  if(atoi(argv[i])!=atoi(argv[i-1]))
   jednaki=0;
  if(atoi(argv[i])>atoi(argv[i-1]))
   opadajuce=0;
  if(atoi(argv[i])<atoi(argv[i-1]))
   rastuce=0;
  if(atoi(argv[i])==atoi(argv[i-1])){
   opadajuce=0;
   rastuce=0;
  }
  suma+=atoi(argv[i]);
  proizvod*=atoi(argv[i]);
 }
 
 if(jednaki)
  printf("0\n");
 else if(rastuce)
  printf("%d\n", suma);
 else if(opadajuce)
  printf("%d\n", proizvod);
 else
  printf("-\n");
 
 return 0;
}

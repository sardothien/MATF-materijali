/* Kao argumenti komandne linije zadaju se broj k i niz
reci (nepoznat broj reci). Na standardni izlaz ispisati
svaku k-tu rec. U slucaju greske ispisati -1 na 
standardni izlaz za greske. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]){
 if(argc<2)
  greska();
 
 int k=atoi(argv[1]);
 if(k<=0)
  greska();
 
 int i;
 for(i=1; i<argc; i++){
  if(i%k==0)
   printf("%s ", argv[i+1]);
 }
 printf("\n"); 
 
 return 0;
}

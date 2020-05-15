/* Napisati program koji kao argument komandne linije
dobija pozitivan broj n (n > 0), a nakon toga učitava n
pozitivnih brojeva sa standardnog ulaza i na standardni
izlaz ispisuje prosečnu vrednost unetih brojeva koji su
Nivenovi zaokruženu na dve decimale. U slučaju greške
ispisati -1 na standardni izlaz za grešku. Uputstvo:
Broj je Nivenov ukoliko je deljiv sumom svojih cifara.
Na primer broj 20 jeste Nivenov dok broj 28 nije. */

#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

int nivenov(int br){
 int suma=0;
 int n=br;
 while(br){
  suma+=br%10;
  br/=10;
 }
 
 if(n%suma==0)
  return 1; 
 return 0;
}

int main(int argc, char *argv[]){
 if(argc!=2)
  greska();
 
 int n=atoi(argv[1]);
 if(n<=0)
  greska();
 
 int *niz=malloc(n*sizeof(int));
 if(niz==NULL)
  greska();
  
 int i;
 int suma=0, br=0;
 for(i=0; i<n; i++){
  scanf("%d", &niz[i]);
  if(niz[i]<=0)
   greska();
  if(nivenov(niz[i])){
   suma+=niz[i];
   br++;
  }
 }
 
 if(br==0)
  printf("0.00\n");
 else
  printf("%.2f\n", (float)suma/br);
  
 free(niz);
 
 return 0;
}

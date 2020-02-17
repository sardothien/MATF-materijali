/* U datoteci polinomi.txt se nalaze polinomi zadati
svojim koeficijentima. Prvo se zadaje ukupan broj 
polinoma, a zatim u svakom narednom redu po 1 polinom.
Svaki od tih redova sadrzi ime polinoma[20], broj 
koeficijenata polinoma (int n), i koeficijente (float).
Sortirati polinome opadajuce prema stepenu polinoma, a
ukoliko su oni isti po vrednostima koeficijenata, pocev
od najviseg ka nizim. Ispisati imena sortiranih polinoma
na standardni izlaz. Koristiti dinamicku alokaciju. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char naziv[21];
 int n;
 float *koef;
}POLINOM; 

int poredi(POLINOM p1, POLINOM p2){
 if(p1.n<p2.n)
  return -1;
 if(p1.n>p2.n)
  return 1;
 
 int i;
 for(i=p1.n-1; i>=0; i--){
  if(p1.koef[i]<p2.koef[i])
   return -1;
  if(p1.koef[i]>p2.koef[i])
   return 1;
 }
 return 0;
}

int main(int argc, char *argv[]){
 FILE *in=fopen("polinomi.txt", "r");
 if(in==NULL)
  greska();
  
 int n;
 fscanf(in, "%d", &n);
 if(n<0)
  greska();
 
 POLINOM *niz=malloc(n*sizeof(POLINOM));
 if(niz==NULL)
  greska();
 
 int i, j;
 for(i=0; i<n; i++){
  fscanf(in, "%s%d", niz[i].naziv, &niz[i].n);
  niz[i].koef=malloc(niz[i].n*sizeof(float));
  if(niz[i].koef==NULL)
   greska();
  for(j=0; j<niz[i].n; j++)
   fscanf(in, "%f", &niz[i].koef[j]);
 }
 
 for(i=0; i<n; i++){
  for(j=i+1; j<n; j++){
   if(poredi(niz[i], niz[j])<0){
    POLINOM tmp=niz[i];
    niz[i]=niz[j];
    niz[j]=tmp;
   }
  }
 }
 
 for(i=0; i<n; i++)
  printf("%s\n", niz[i].naziv);
 
 for(i=0; i<n; i++)
  free(niz[i].koef);
 
 free(niz);
 fclose(in);
  
 return 0;
}

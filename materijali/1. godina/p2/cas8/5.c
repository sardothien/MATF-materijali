/* U datoteci duzi.txt se nalazi spisak duzi zadat tackama. Format
datoteke je takav da je najpre zadat broj duzi, a pitom u svakom
narednom redu duz u vidu cetiri koordinate: Ax Ay Bx By (tipa float).
Potrebno je ucitati duzi iz datoteke, sortirati ih opadajuce prema
njihovoj duzini i ispisati tako sortirani niz na standardni izlaz. U
svakom redu se ispisuju Ax Ay Bx By d, gde je d duzina duzi.
Sve podatke ispisati zaokruzene na dve decimale. Koristiti dinamicku
alokaciju memorije. U slucaju greske ispisati −1 na standardni izlaz.
Za koren broja tipa float koristiti funkciju sqrtf. Zadatak resiti
primenom:
a. insertion sort-a
b. selection sort-a
c. merge sort-a
d. quick sort-a
e. bibliotecke qsort funkcije */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 float ax;
 float ay;
 float bx;
 float by;
 float duzina;
}DUZ;

// pod a)
void insertion(int n, DUZ *d){
 int i, j;
 DUZ tmp;
 for(i=1; i<n; i++){
  for(j=i; j>=0; j--){
   if(d[j].duzina > d[j-1].duzina){
    tmp=d[j];
    d[j]=d[j-1];
    d[j-1]=tmp;
   }
   else
    break;
  }
 }
}
// pod b)
void selection(int n, DUZ *d){
 int i, j;
 int poz_max;
 DUZ tmp;
 for(i=0; i<n-1; i++){
  poz_max=i;
  for(j=i+1; j<n; j++){
   if(d[j].duzina > d[poz_max].duzina)
    poz_max=j;
  }
  if(poz_max!=i){
   tmp=d[i];
   d[i]=d[poz_max];
   d[poz_max]=tmp;
  }
 }
}
// pod c)
void merge(DUZ *niz, int l, int d, DUZ *pomocni){ 
 if(l>=d)
  return;
 int s=l+(d-l)/2;
 merge(niz, l, s, pomocni);
 merge(niz, s+1, d, pomocni);
 
 int i=l, j=s+1, k=l;
 while(i<=s && j<=d){
  if(niz[i].duzina > niz[j].duzina)
   pomocni[k++]=niz[i++];
  else
   pomocni[k++]=niz[j++];
 }
 while(i<=s)
  pomocni[k++]=niz[i++];
 while(j<=d)
  pomocni[k++]=niz[j++];
 
 for(i=l; i<=d; i++)
  niz[i]=pomocni[i]; 
}
// pod d)
void zamena(DUZ *d, int i, int j){ 
 DUZ tmp;
 if(i!=j){
  tmp=d[i];
  d[i]=d[j];
  d[j]=tmp;
 }
}
void quicksort(DUZ *niz, int l, int d){ 
 if(l>=d)
  return;
 
 int pp=l;
 float pivot=niz[l].duzina;
 int i;
 for(i=l+1; i<=d; i++){
  if(niz[i].duzina > pivot){
   pp++;
   zamena(niz, i, pp);
  }
 }
 zamena(niz, l, pp);
 quicksort(niz, l, pp-1);
 quicksort(niz, pp+1, d);
}
// pod e)
int poredi(const void *a, const void *b){ // za qsort j)
 DUZ x=*(DUZ*)a;
 DUZ y=*(DUZ*)b;
 if(x.duzina < y.duzina)
  return 1;
 else if(x.duzina > y.duzina)
  return -1;

 return 0;
}


int main(int argc, char *argv[]){
 if(argc!=2)
  greska();
 
 FILE *in=fopen("duzi.txt", "r");
 if(in==NULL)
  greska();
 
 int n; 
 fscanf(in, "%d", &n);
 if(n<=0)
  greska();
  
 DUZ *d=malloc(n*sizeof(DUZ));
 if(d==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++){
  fscanf(in, "%f%f%f%f", &d[i].ax, &d[i].ay, &d[i].bx, &d[i].by);
  d[i].duzina = sqrtf((d[i].ax-d[i].bx)*(d[i].ax-d[i].bx) 
                   + (d[i].ay-d[i].by)*(d[i].ay-d[i].by));
 }
 
 fclose(in);
 
 DUZ *pomocni=malloc(n*sizeof(DUZ));
 if(pomocni==NULL)
  greska();
 
 if(strcmp(argv[1], "-i")==0)
  insertion(n, d);
 else if(strcmp(argv[1], "-s")==0)
  selection(n, d);
 else if(strcmp(argv[1], "-m")==0)
  merge(d, 0, n-1, pomocni);
 else if(strcmp(argv[1], "-q")==0)
  quicksort(d, 0, n-1); 
 else if(strcmp(argv[1], "-qsort")==0)
  qsort(d, n, sizeof(DUZ), poredi);
 else 
  greska();
 
 for(i=0; i<n; i++)
  printf("%.2f %.2f %.2f %.2f %.2f\n", d[i].ax, d[i].ay, d[i].bx, 
                                       d[i].by, d[i].duzina);
  

 free(d);
 free(pomocni);
  
 return 0;
}

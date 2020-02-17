/* U datoteci proizvodi.txt se nalazi spisak proizvoda. Format
datoteke je takav da je najpre zadat broj proizvoda, a zatim u svakom
narednom redu naziv proizvoda (maksimalno 20 karaktera), cena i
kolicina (tipa float). Potrebno je ucitati proizvode iz datoteke,
sortirati ih opadajuce prema ukupnoj vrednosti (cena*kolicina) i
ispisati tako sortirani niz na standardni izlaz. U svakom redu se
ispisuju naziv, cena, kolicina i ukupna vrednost. Sve podatke ispisati
zaokruzene na dve decimale. Koristiti dinamicku alokaciju memorije. U
slucaju greske ispisati −1 na standardni izlaz. Zadatak resiti
primenom:
a. insertion sort-a
b. selection sort-a
c. merge sort-a
d. quick sort-a
e. bibliotecke qsort funkcije*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 21
 
void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}
 
typedef struct{
 char naziv[MAX];
 float cena;
 float kolicina;
 float vrednost;
}PROIZVOD;

// pod a)
void insertion(int n, PROIZVOD *p){
 int i, j;
 PROIZVOD tmp;
 for(i=1; i<n; i++){
  for(j=i; j>=0; j--){
   if(p[j].vrednost > p[j-1].vrednost){
    tmp=p[j];
    p[j]=p[j-1];
    p[j-1]=tmp;
   }
   else
    break;
  }
 }
}
// pod b)
void selection(int n, PROIZVOD *p){
 int i, j;
 int poz_max;
 PROIZVOD tmp;
 for(i=0; i<n-1; i++){
  poz_max=i;
  for(j=i+1; j<n; j++){
   if(p[j].vrednost > p[poz_max].vrednost)
    poz_max=j;
  }
  if(poz_max!=i){
   tmp=p[i];
   p[i]=p[poz_max];
   p[poz_max]=tmp;
  }
 }
}
// pod c)
void merge(PROIZVOD *p, int l, int d, PROIZVOD *pomocni){ 
 if(l>=d)
  return;
 int s=l+(d-l)/2;
 merge(p, l, s, pomocni);
 merge(p, s+1, d, pomocni);
 
 int i=l, j=s+1, k=l;
 while(i<=s && j<=d){
  if(p[i].vrednost > p[j].vrednost)
   pomocni[k++]=p[i++];
  else
   pomocni[k++]=p[j++];
 }
 while(i<=s)
  pomocni[k++]=p[i++];
 while(j<=d)
  pomocni[k++]=p[j++];
 
 for(i=l; i<=d; i++)
  p[i]=pomocni[i]; 
}
// pod d)
void zamena(PROIZVOD *p, int i, int j){ 
 PROIZVOD tmp;
 if(i!=j){
  tmp=p[i];
  p[i]=p[j];
  p[j]=tmp;
 }
}
void quicksort(PROIZVOD *p, int l, int d){ 
 if(l>=d)
  return;
 
 int pp=l;
 float pivot=p[l].vrednost;
 int i;
 for(i=l+1; i<=d; i++){
  if(p[i].vrednost > pivot){
   pp++;
   zamena(p, i, pp);
  }
 }
 zamena(p, l, pp);
 quicksort(p, l, pp-1);
 quicksort(p, pp+1, d);
}
// pod e)
int poredi(const void *a, const void *b){
 PROIZVOD x=*(PROIZVOD*)a;
 PROIZVOD y=*(PROIZVOD*)b;
 if(x.vrednost < y.vrednost)
  return 1;
 else if(x.vrednost > y.vrednost)
  return -1;

 return 0;
}

 
int main(int argc, char* argv[]){
 if(argc!=2)
  greska();
		
 FILE *in=fopen("proizvodi.txt", "r");
 if(in==NULL)
  greska();
 		
 int n;
 fscanf(in, "%d", &n);
 
 PROIZVOD *p;
 p=malloc(n*sizeof(PROIZVOD));
 if(p==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++){
  fscanf(in, "%s%f%f", p[i].naziv, &p[i].cena, &p[i].kolicina);
  p[i].vrednost = p[i].cena * p[i].kolicina;
 }

 PROIZVOD *pomocni=malloc(n*sizeof(PROIZVOD));
 if(pomocni==NULL)
  greska();
  
 if(strcmp(argv[1], "-i")==0)
  insertion(n, p);
 else if(strcmp(argv[1], "-s")==0)
  selection(n, p);
 else if(strcmp(argv[1], "-m")==0)
  merge(p, 0, n-1, pomocni);
 else if(strcmp(argv[1], "-q")==0)
  quicksort(p, 0, n-1);
 else if(strcmp(argv[1], "-qsort")==0)
  qsort(p, n, sizeof(PROIZVOD), poredi);
 else
  greska();

 for(i=0; i<n; i++)
  printf("%s %.2f %.2f %.2f\n", p[i].naziv, p[i].cena, p[i].kolicina,
                            p[i].vrednost);
		
 free(p);
 fclose(in);
 return 0;
}

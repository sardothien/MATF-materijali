/* Sa standardnog ulaza se zadaje n, a zatim n niski ne duzih od 50
karaktera. Kao argument komandne linije se zadaje opcija. Napisati
program koji u zavisnosti od zadate opcije sortira uneti niz niski:
a. Za opciju -i, primenom insertion sort-a, leksikografski rastuce
b. Za opciju -s, primenom selection sort-a, leksikografski rastuce
c. Za opciju -m, primenom merge sort-a, leksikografski rastuce
d. Za opciju -q, primenom quick sort-a, leksikografski rastuce
e. Za opciju -qsort, primenom qsort funkcije, leksikografski rastuce
f. Za opciju -ir, primenom insertion sort-a, opadajuce po duzini, a
   ako su niske jednake duzine, onda leksikografski rastuce
g. Za opciju -sr, primenom selection sort-a, opadajuce po duzini, a
   ako su niske jednake duzine, onda leksikografski rastuce
h. Za opciju -mr, primenom merge sort-a, opadajuce po duzini, a ako
   su niske jednake duzine, onda leksikografski rastuce
i. Za opciju -qr, primenom quick sort-a, opadajuce po duzini, a ako
   su niske jednake duzine, onda leksikografski rastuce
j. Za opciju -qsortr, primenom qsort funkcije, opadajuce po duzini,
   a ako su niske jednake duzine, onda leksikografski rastuce
Na standardni izlaz ispisati rezultujuci niz. U slucaju greske na
standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void insertion(int n, char **niz){ // pod a)
 int i, j;
 int *tmp[51];
 for(i=1; i<n; i++){
  for(j=i; j>0; j--){
   if(strcmp(niz[j], niz[j-1]) < 0){
    strcpy(tmp, niz[j]);
    strcpy(niz[j], niz[j-1]);
    strcpy(niz[j-1], tmp);
   }
   else
    break;
  }
 }
}

void selection(int n, char **niz){ // pod b)
 int i, j;
 int poz_min;
 char *tmp[51];
 for(i=0; i<n-1; i++){
  poz_min=i;
  for(j=i+1; j<n; j++){
   if(strcmp(niz[j], niz[poz_min]) < 0)
    poz_min=j;
  }
  if(poz_min!=i){
   strcpy(tmp, niz[i]);
   strcpy(niz[i], niz[poz_min]);
   strcpy(niz[poz_min], tmp);
  }
 }
}

void merge(char **niz, int l, int d, char **pomocni){ // pod c)
 if(l>=d)
  return;
 int s=l+(d-l)/2;
 merge(niz, l, s, pomocni);
 merge(niz, s+1, d, pomocni);
 
 int i=l, j=s+1, k=l;
 while(i<=s && j<=d){
  if(strcmp(niz[i], niz[j]) < 0){
   pomocni[k]=niz[i];
   i++;
   k++;
  }
  else{
   pomocni[k]=niz[j];
   j++;
   k++;
  }
 }
 while(i<=s)
  pomocni[k++]=niz[i++];
 while(j<=d)
  pomocni[k++]=niz[j++];
 
 for(i=l; i<=d; i++)
  niz[i]=pomocni[i]; 
}

void zamena(char **niz, int i, int j){ // za quick sort
 char *tmp[51];
 if(i!=j){
  strcpy(tmp, niz[i]);
  strcpy(niz[i], niz[j]);
  strcpy(niz[j], tmp);
 }
}

void quicksort(char **niz, int l, int d){ // pod d)
 if(l>=d)
  return;
 
 int pp=l; // pp - pozicija pivota
 char *pivot=niz[l];
 int i;
 for(i=l+1; i<=d; i++){
  if(strcmp(niz[i], pivot) < 0){
   pp++;
   zamena(niz, i, pp);
  }
 }
 zamena(niz, l, pp);
 quicksort(niz, l, pp-1);
 quicksort(niz, pp+1, d);
}

int poredi(const void *a, const void *b){ // za qsort e)
 char *x=*((char*)a);
 char *y=*((char*)b);
 if(strcmp(x, y) < 0)
  return -1;
 else if(strcmp(x, y) > 0)
  return 1;

 return 0;
}

////////////////////////////////////////////////////////////////////

void insertionr(int n, char **niz){ // pod f)
 int i, j;
 int *tmp[51];
 for(i=1; i<n; i++){
  for(j=i; j>0; j--){
   if(strlen(niz[j]) > strlen(niz[j-1])){
    if(strcmp(niz[j], niz[j-1]) > 0){
     strcpy(tmp, niz[j]);
     strcpy(niz[j], niz[j-1]);
     strcpy(niz[j-1], tmp);
    }
   }
   else
    break;
  }
 }
}

void selectionr(int n, char **niz){ // pod g)
 int i, j;
 int poz_min;
 char *tmp[51];
 for(i=0; i<n-1; i++){
  poz_min=i;
  for(j=i+1; j<n; j++){
   if(strlen(niz[j]) > strlen(niz[j-1])){
    if(strcmp(niz[j], niz[poz_min]) > 0)
     poz_min=j;
   }
  }
  if(poz_min!=i){
   strcpy(tmp, niz[i]);
   strcpy(niz[i], niz[poz_min]);
   strcpy(niz[poz_min], tmp);
  }
 }
}

void merger(char **niz, int l, int d, char **pomocni){ // pod h)
 if(l>=d)
  return;
 int s=l+(d-l)/2;
 merger(niz, l, s, pomocni);
 merger(niz, s+1, d, pomocni);
 
 int i=l, j=s+1, k=l;
 while(i<=s && j<=d){
  if(strcmp(niz[i], niz[j]) > 0){
   pomocni[k]=niz[i];
   i++;
   k++;
  }
  else{
   pomocni[k]=niz[j];
   j++;
   k++;
  }
 }
 
 while(i<=s)
  pomocni[k++]=niz[i++];
 while(j<=d)
  pomocni[k++]=niz[j++];
 
 for(i=l; i<=d; i++)
  niz[i]=pomocni[i]; 
}

void quicksortr(char **niz, int l, int d){ // pod i)
 if(l>=d)
  return;
 
 int pp=l; // pp - pozicija pivota
 char *pivot=niz[l];
 int i;
 for(i=l+1; i<=d; i++){
  if(strcmp(niz[i], pivot) > 0){
   pp++;
   zamena(niz, i, pp);
  }
 }
 zamena(niz, l, pp);
 quicksortr(niz, l, pp-1);
 quicksortr(niz, pp+1, d);
}


int poredi1(const void *a, const void *b){ // za qsort j)
 char *x=*((char*)a);
 char *y=*((char*)b);
 if(strcmp(x, y) < 0)
  return 1;
 else if(strcmp(x, y) > 0)
  return -1;

 return 0;
}

int main(int argc, char *argv[]){
 if(argc!=2)
  greska();
 
 int n;
 scanf("%d", &n);
 if(n<=0)
  greska();
 
 char **niz=malloc(n*sizeof(char*));
 if(niz==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++){
  niz[i]=malloc(51*sizeof(char));
  if(niz[i]==NULL)
   greska();
 }
 for(i=0; i<n; i++)
  scanf("%s", niz[i]);
  
 char **pomocni=malloc(n*sizeof(char*));
 if(pomocni==NULL)
  greska();
 for(i=0; i<n; i++){
  pomocni[i]=malloc(51*sizeof(char));
  if(pomocni[i]==NULL)
   greska();
 }
 
 if(strcmp(argv[1], "-i")==0)
  insertion(n, niz);
 else if(strcmp(argv[1], "-s")==0)
  selection(n, niz);
 else if(strcmp(argv[1], "-m")==0)
  merge(niz, 0, n-1, pomocni);
 else if(strcmp(argv[1], "-q")==0)
  quicksort(niz, 0, n-1); 
 else if(strcmp(argv[1], "-qsort")==0)
  qsort(niz, n, sizeof(char), poredi);
 else if(strcmp(argv[1], "-ir")==0)
  insertionr(n, niz); 
 else if(strcmp(argv[1], "-sr")==0)
  selectionr(n, niz); 
 else if(strcmp(argv[1], "-mr")==0)
  merger(niz, 0, n-1, pomocni);
 else if(strcmp(argv[1], "-qr")==0)
  quicksortr(niz, 0, n-1); 
 else if(strcmp(argv[1], "-qsortr")==0)
  qsort(niz, n, sizeof(char), poredi1);
 else 
  greska();
 
 for(i=0; i<n; i++)
  printf("%s\n", niz[i]); 
 
 for(i=0; i<n; i++)
  free(niz[i]);
 free(niz);
 
 for(i=0; i<n; i++)
  free(pomocni[i]);
 free(pomocni);
 
 return 0;
}

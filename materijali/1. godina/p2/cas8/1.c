/* Sa standardnog ulaza se zadaje n, a zatim n celih brojeva.
Kao argument komandne linije se zadaje opcija. Napisati
program koji u zavisnosti od zadate opcije sortira uneti niz
brojeva:
a. Za opciju -i, primenom insertion sort-a, rastuce
b. Za opciju -s, primenom selection sort-a, rastuce
c. Za opciju -m, primenom merge sort-a, rastuce
d. Za opciju -q, primenom quick sort-a, rastuce
e. Za opciju -qsort, primenom bibliotecke qsort funkcije, rastuce
f. Za opciju -ir, primenom insertion sort-a, opadajuce
g. Za opciju -sr, primenom selection sort-a, opadajuce
h. Za opciju -mr, primenom merge sort-a, opadajuce
i. Za opciju -qr, primenom quick sort-a, opadajuce
j. Za opciju -qsortr, primenom bibliotecke qsort funkcije, opadajuce
Na standardni izlaz ispisati rezultujuci niz. U slucaju greske na
standardni izlaz za greske ispisati -1. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

void insertion(int n, int *niz){ // pod a)
 int i, j;
 int tmp;
 for(i=1; i<n; i++){
  for(j=i; j>0; j--){
   if(niz[j] < niz[j-1]){
    tmp=niz[j];
    niz[j]=niz[j-1];
    niz[j-1]=tmp;
   }
   else
    break;
  }
 }
}

void selection(int n, int *niz){ // pod b)
 int i, j;
 int poz_min, tmp;
 for(i=0; i<n-1; i++){
  poz_min=i;
  for(j=i+1; j<n; j++){
   if(niz[j] < niz[poz_min])
    poz_min=j;
  }
  if(poz_min!=i){
   tmp=niz[i];
   niz[i]=niz[poz_min];
   niz[poz_min]=tmp;
  }
 }
}

void merge(int *niz, int l, int d, int *pomocni){ // pod c)
 if(l>=d)
  return;
 int s=l+(d-l)/2;
 merge(niz, l, s, pomocni);
 merge(niz, s+1, d, pomocni);
 
 int i=l, j=s+1, k=l;
 
 while(i<=s && j<=d){
  if(niz[i] < niz[j])
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

void zamena(int *niz, int i, int j){ // za quick sort
 int tmp;
 if(i!=j){
  tmp=niz[i];
  niz[i]=niz[j];
  niz[j]=tmp;
 }
}

void quicksort(int *niz, int l, int d){ // pod d)
 if(l>=d)
  return;
 
 int pp=l; // pp - pozicija pivota
 int pivot=niz[l];
 int i;
 for(i=l+1; i<=d; i++){
  if(niz[i] < pivot){
   pp++;
   zamena(niz, i, pp);
  }
 }
 zamena(niz, l, pp);
 quicksort(niz, l, pp-1);
 quicksort(niz, pp+1, d);
}

int poredi(const void *a, const void *b){ // za qsort e)
 int x=*((int*)a);
 int y=*((int*)b);
 if(x<y)
  return -1;
 else if(x>y)
  return 1;

 return 0;
}

////////////////////////////////////////////////////////////////////

void insertionr(int n, int *niz){ // pod f)
 int i, j;
 int tmp;
 for(i=1; i<n; i++){
  for(j=i; j>0; j--){
   if(niz[j] > niz[j-1]){
    tmp=niz[j];
    niz[j]=niz[j-1];
    niz[j-1]=tmp;
   }
   else
    break;
  }
 }
}

void selectionr(int n, int *niz){ // pod g)
 int i, j;
 int poz_min, tmp;
 for(i=0; i<n-1; i++){
  poz_min=i;
  for(j=i+1; j<n; j++){
   if(niz[j] > niz[poz_min])
    poz_min=j;
  }
  if(poz_min!=i){
   tmp=niz[i];
   niz[i]=niz[poz_min];
   niz[poz_min]=tmp;
  }
 }
}

void merger(int *niz, int l, int d, int *pomocni){ // pod h)
 if(l>=d)
  return;
 int s=l+(d-l)/2;
 merger(niz, l, s, pomocni);
 merger(niz, s+1, d, pomocni);
 
 int i=l, j=s+1, k=l;
 while(i<=s && j<=d){
  if(niz[i] > niz[j]){
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

void quicksortr(int *niz, int l, int d){ // pod i)
 if(l>=d)
  return;
 
 int pp=l; // pp - pozicija pivota
 int pivot=niz[l];
 int i;
 for(i=l; i<=d; i++){
  if(niz[i] > pivot){
   pp++;
   zamena(niz, i, pp);
  }
 }
 zamena(niz, l, pp);
 quicksortr(niz, l, pp-1);
 quicksortr(niz, pp+1, d);
}

int poredi1(const void *a, const void *b){ // za qsort j)
 int x=*((int*)a);
 int y=*((int*)b);
 if(x<y)
  return 1;
 else if(x>y)
  return -1;

 return 0;
}


int main(int argc, char *argv[]){
 if(argc!=2)
  greska();
 
 int n;
 int *niz;
 scanf("%d", &n);
 if(n<=0)
  greska();
 
 niz=malloc(n*sizeof(int));
 if(niz==NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++)
  scanf("%d", &niz[i]);
 
 int *pomocni=malloc(n*sizeof(int));
 if(pomocni==NULL)
  greska();
 
 if(strcmp(argv[1], "-i")==0)
  insertion(n, niz);
 else if(strcmp(argv[1], "-s")==0)
  selection(n, niz);
 else if(strcmp(argv[1], "-m")==0)
  merge(niz, 0, n-1, pomocni);
 else if(strcmp(argv[1], "-q")==0)
  quicksort(niz, 0, n-1); 
 else if(strcmp(argv[1], "-qsort")==0)
  qsort(niz, n, sizeof(int), poredi); 
 else if(strcmp(argv[1], "-ir")==0)
  insertionr(n, niz); 
 else if(strcmp(argv[1], "-sr")==0)
  selectionr(n, niz); 
 else if(strcmp(argv[1], "-mr")==0)
  merger(niz, 0, n-1, pomocni);
 else if(strcmp(argv[1], "-qr")==0)
  quicksortr(niz, 0, n-1); 
 else if(strcmp(argv[1], "-qsortr")==0)
  qsort(niz, n, sizeof(int), poredi1);
 else 
  greska();
 
 for(i=0; i<n; i++)
  printf("%d ", niz[i]);
  
 printf("\n");
 
 free(niz);
 free(pomocni);
  
 return 0;
}

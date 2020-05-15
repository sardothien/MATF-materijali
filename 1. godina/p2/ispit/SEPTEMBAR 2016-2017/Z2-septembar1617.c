#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char naziv[21];
 float cena;
 int kolicina;
 float vrednost;
}PROIZVOD;

int poredi(const void *a, const void *b){
 PROIZVOD *x = (PROIZVOD*)a;
 PROIZVOD *y = (PROIZVOD*)b;
 
 if(x->vrednost < y->vrednost)
  return -1;
 else if(x->vrednost > y->vrednost)
  return 1;
 else
  return -1*strcmp(x->naziv, y->naziv);
}

int main(){
 FILE *in = fopen("proizvodi.txt", "r");
 if(in == NULL)
  greska();
 
 int j = 5;
 PROIZVOD *p = (PROIZVOD*)malloc(j*sizeof(PROIZVOD));
 if(p == NULL)
  greska();
 
 int i = 0;
 while(fscanf(in, "%s%f%d", p[i].naziv, 
       &p[i].cena, &p[i].kolicina) == 3){
  if(p[i].cena <= 0 || p[i].kolicina <= 0)
   greska();
  p[i].vrednost = p[i].cena * p[i].kolicina;
  i++;
  if(i == j){
   j *= 2;
   p = realloc(p, j*sizeof(PROIZVOD));
   if(p == NULL)
    greska();
  }      
 }
 
 fclose(in);
 
 int n = i;
 
 qsort(p, n, sizeof(PROIZVOD), poredi);
 
 for(i=0; i<n; i++)
  printf("%s %.2f\n", p[i].naziv, p[i].vrednost);
 
 return 0;
}

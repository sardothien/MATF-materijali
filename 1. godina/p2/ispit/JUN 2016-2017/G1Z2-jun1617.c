#include <stdio.h>
#include <stdlib.h>
#define MAX 20

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char domacin[MAX];
 char gost[MAX];
 int gol_domacin;
 int gol_gost;
 int gol_razlika;
} DUEL;

void zameni(DUEL *d, int i, int j){
 DUEL tmp;
 tmp = d[i];
 d[i] = d[j];
 d[j] = tmp;
}

int insertion_sort(DUEL *d, int n){
 int i, j;
 for(i=1; i<n; i++){
  for(j=i; j>0; j--){
   if(d[j].gol_razlika < d[j-1].gol_razlika)
    zameni(d, j, j-1);
   else if(d[j].gol_razlika == d[j-1].gol_razlika){
    int l = strcmp(d[j].domacin, d[j-1].domacin);
    if(l > 0)
     zameni(d, j, j-1);
    else if(l == 0){
     int  k = strcmp(d[j].gost, d[j-1].gost);
     if(k < 0)
      zameni(d, j, j-1);
    }    
   }
   else 
    break;
  }
 }
}  

int main(){
 int n;
 scanf("%d", &n);
 if(n < 0)
  greska();
 
 DUEL *d = malloc(n*sizeof(DUEL));
 if(d == NULL)
  greska();
  
 int i;
 for(i=0; i<n; i++){
  scanf("%s%s%d%d", d[i].domacin, d[i].gost, 
                   &d[i].gol_domacin, &d[i].gol_gost);
  if(d[i].gol_domacin < 0 || d[i].gol_gost < 0)
   greska();
  d[i].gol_razlika = abs(d[i].gol_domacin - d[i].gol_gost); 
 }
 
 insertion_sort(d, n); 
 for(i=0; i<n; i++)
  printf("%s %s\n", d[i].domacin, d[i].gost);
 
 free(d);               
 
 return 0;
}

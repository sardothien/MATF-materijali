#include <stdio.h>
#include <stdlib.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char grad1[26];
 char grad2[26];
 float km;
 int tr_min;
}LET;

int poredi(const void *a, const void *b){
 LET *x = (LET*)a; 
 LET *y = (LET*)b;
 
 if(x->km < y->km)
  return 1;
 else if(x->km > y->km)
  return -1;
 else{ 
  if(x->tr_min > y->tr_min)
   return 1;
  else if(x->tr_min < y->tr_min)
   return -1;
 }
}

int main(){
 FILE *in = fopen("letovi.txt", "r");
 if(in == NULL)
  greska();
 
 int j = 5;
 LET *l = malloc(j*sizeof(LET));
 if(l == NULL)
  greska();
 
 int i = 0;
 while(fscanf(in, "%s%s%f%d", l[i].grad1, l[i].grad2,
                        &l[i].km, &l[i].tr_min) == 4){
  if(l[i].km <= 0 || l[i].tr_min <=0 )
   greska();
  i++;
  if(i == j){
   j *= 2;
   l = realloc(l, j*sizeof(LET));
   if(l == NULL)
    greska();
  }
 }
 
 int n = i;
 fclose(in);
 
 qsort(l, n, sizeof(LET), poredi);
 for(i=0; i<n; i++)
  printf("%s %s %.2f %d\n", l[i].grad1, l[i].grad2,
                            l[i].km, l[i].tr_min);
 return 0;
}

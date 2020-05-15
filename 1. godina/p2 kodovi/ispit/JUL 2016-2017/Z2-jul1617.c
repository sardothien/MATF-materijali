#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char predmet[16];
 int dan;
 int mesec;
 int godina;
} ISPIT;

int poredi(const void *a, const void *b){
 ISPIT *x = (ISPIT*)a;
 ISPIT *y = (ISPIT*)b;
 if(x->godina < y->godina)
  return -1;
 else if(x->godina > y->godina)
  return 1;
 else{
  if(x->mesec > y->mesec)
   return 1;
  else if(x->mesec < y->mesec)
   return -1;
  else{
   if(x->dan < y->dan)
    return -1;
   else if(x->dan > y->dan)
    return 1;
   else
    return strcmp(y->predmet, x->predmet);
  }
 }
}

int main(){
 FILE *in = fopen("ispiti.txt", "r");
 if(in == NULL)
  greska();
 
 int j = 5;
 ISPIT *s = (ISPIT*)malloc(j*sizeof(ISPIT));
 if(s == NULL)
  greska();
 
 int i = 0;
 while(fscanf(in, "%s%d%d%d", s[i].predmet, &s[i].dan, 
                             &s[i].mesec, &s[i].godina) == 4){
  if(s[i].dan <= 0 || s[i].mesec <= 0 
  || s[i].mesec >= 13 || s[i].godina <= 0)
    greska();
  i++;
  if(i == j){
   j *= 2;
   s = realloc(s, j*sizeof(ISPIT));
   if(s == NULL)
    greska();
  }
 }
 
 fclose(in);
 
 int n = i;
  
 qsort(s, n, sizeof(ISPIT), poredi);
 for(i=0; i<n; i++)
  printf("%s ", s[i].predmet);
 printf("\n");
 
 return 0;
}

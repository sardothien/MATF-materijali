#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21

void greska(){
 fprintf(stderr, "-1\n");
 exit(EXIT_FAILURE);
}

typedef struct {
 char ime[MAX];
 char prezime[MAX];
 float prosek;
} STUDENT;

int poredi(const void *a, const void *b){
 STUDENT *prvi = (STUDENT*)a;
 STUDENT *drugi = (STUDENT*)b;
 
 if(prvi->prosek < drugi->prosek)
  return 1;
 else if(prvi->prosek > drugi->prosek)
  return -1;
 else{
  int prezimena = strcmp(prvi->prezime, drugi->prezime);
  if(prezimena > 0)
   return 1;
  else if(prezimena < 0)
   return -1;
  else
   return -1*strcmp(prvi->ime, drugi->ime);
 }

}

int main(){
 float min_pr;
 int n;
 scanf("%f%d", &min_pr, &n);
 if(min_pr < 6 || min_pr > 10)
  greska();
 if(n <= 0)
  greska();
 
 STUDENT *s = malloc(n*sizeof(STUDENT));
 if(s == NULL)
  greska();
 
 int i;
 for(i=0; i<n; i++){
  scanf("%s%s%f", s[i].prezime, s[i].ime, &s[i].prosek);
  if(s[i].prosek < 6 || s[i].prosek > 10)
   greska();
 }
 
 qsort(s, n, sizeof(STUDENT), poredi);
 
 int br = 0;
 for(i=0; i<n; i++)
  if(s[i].prosek >= min_pr){
   printf("%s %s %.2f\n", s[i].prezime, s[i].ime, s[i].prosek); 
   br++;
  }
 
 if(br == 0)
  printf("-\n");
 
 free(s);
 
 return 0;
}

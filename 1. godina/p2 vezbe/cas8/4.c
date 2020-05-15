/* U datoteci studenti.txt se nalaze podaci o
studentima (ime, prezime, smer, prosecna ocena). Kao
argument komandne linije se zadaje opcija. Napisati
program koji u zavisnosti od zadate opcije sortira
uneti niz:
a. Za opciju -i, primenom insertion sort-a, po proseku
   opadajuce, a u slucaju istog proseka, po prezimenu
   leksikografski
b. Za opciju -s, primenom selection sort-a, po proseku
   rastuce, a u slucaju istog proseka, po smeru 
   opadajuce
c. Za opciju -q, primenom quick sort-a, po proseku
   opadajuce, a u slucaju istog proseka, po prezimenu
   leksikografski
d. Za opciju -qsort, primenom bibliotecke qsort
   funkcije, po proseku rastuce, a u slucaju istog
   proseka, po smeru opadajuce
Maksimalna duzina imena, kao i prezimena studenta je
20 karaktera. Smer je jedan karakter i moze biti
I, R, M, N, V ili L. Prosecna ocena je realan broj
izmedju 5 i 10. U slucaju greske na standardni izlaz za
greske ispisati -1. */

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
 char smer;
 float prosek;
}STUDENT;

// pod a)
void insertion(int n, STUDENT *s){ 
 int i, j;
 float tmp;
 for(i=1; i<n; i++){
  for(j=i; j>0; j--){
   if(s[j].prosek > s[j-1].prosek || (s[j].prosek == s[j-1].prosek 
    && strcmp(s[j].prezime, s[j-1].prezime) < 0)){
    tmp=s[j].prosek;
    s[j].prosek=s[j-1].prosek;
    s[j-1].prosek=tmp;
   }
   else
    break;
  }
 }
}

//pod b)
void selection(int n, STUDENT *s){ 
 int i, j;
 int poz_min;
 float tmp;
 for(i=0; i<n-1; i++){
  poz_min=i;
  for(j=i+1; j<n; j++){
   if(s[j].prosek < s[poz_min].prosek)
    poz_min=j;
  }
  if(poz_min!=i){
   tmp=s[i].prosek;
   s[i].prosek=s[poz_min].prosek;
   s[poz_min].prosek=tmp;
  }
 }
}

// pod c)
void razmeni(STUDENT* s, int i, int j){
 STUDENT tmp;
 tmp = s[i];
 s[i] = s[j];
 s[j] = tmp;
}
 
void quicksort(STUDENT* s, int l, int d){
 if(l>=d)
  return;
 int pp=l;
 int i;
 for(i=l+1; i<=d; i++){
  if(s[i].prosek > s[l].prosek || 
    (s[i].prosek == s[l].prosek 
    && strcmp(s[i].prezime, s[l].prezime) < 0))
   razmeni(s, i, ++pp);
 }
 razmeni(s, pp, l);	
 quicksort(s, l, pp-1);
 quicksort(s, pp+1, d);
}

// pod d)
int poredi(const void* a, const void* b){
 STUDENT s1=*(STUDENT*)a;
 STUDENT s2=*(STUDENT*)b;	
 if(s1.prosek > s2. prosek || (s1.prosek == s2.prosek 
    && s1.smer < s2.smer))
  return 1; 
 else if((s1.prosek == s2.prosek && 
          strcmp(s1.prezime, s2.prezime) ==0))
  return 0; 
 else
  return -1;
}
 
int main(int argc, char* argv[]){
 if(argc!=2)
  greska();
  
 FILE *in=fopen("studenti.txt", "r");
 if(in==NULL)
  greska();
 		
 int n;
 fscanf(in, "%d", &n);
 STUDENT *s;
 s=malloc(n*sizeof(STUDENT));
 if(s==NULL)
  greska();
 int i;
 for(i=0; i<n; i++)
  fscanf(in, "%s%s %c%f", s[i].ime, s[i].prezime,
                         &s[i].smer, &s[i].prosek);
                         
 fclose(in);
 
 if(strcmp(argv[1], "-i")==0)
  insertion(n, s);
 else if(strcmp(argv[1], "-s")==0)
  selection(n, s);
 else if(strcmp(argv[1], "-q")==0)
  quicksort(s, 0, n-1);
 else if(strcmp(argv[1], "-qsort") == 0)
  qsort(s, n, sizeof(STUDENT), poredi);
 else
  greska();

 for(i=0; i<n; i++)
  printf("%s %s %c %.2f\n", s[i].ime, s[i].prezime,
                            s[i].smer, s[i].prosek);
		
 free(s);
 
 return 0;
}

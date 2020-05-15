/* Definisati strukturu kojom se opisuje student. Student je
zadat svojim imenom i prezimenom (oba su maksimalne
dužine 30 karaktera), smerom (R, I, V, N, T, O) i prosečnom ocenom.
Napisati program koji učitava podatke o n studenata, zatim učitava 
smer i ispisuje imena i prezimena onih studenta koji su sa datog smera.
Potom ispisati podatke za studenta koji ima najveći prosek. Ako ima
više takvih studenata ispisati sve njih. Maksimalan broj studenata 
je 2000. U slučaju greške ispisati odgovarajuću poruku. */

#include <stdio.h>
#include <stdlib.h>

#define MAXST 2000
#define MAX 31

typedef struct Student{
  char ime[MAX];
  char prezime[MAX];
  char smer;
  float prosek;
} STUDENT;

void provera(char smer){
 if (smer!='R' && smer!='I' && smer!='V' && smer!='N' && smer!='T' && smer!='O'){
  printf("Nekorektan smer.\n");
  exit(EXIT_FAILURE);
 }
}

void ucitaj(STUDENT* s){
  scanf("%s",s->ime);
  scanf("%s",s->prezime);
  getchar();
  scanf("%c",&s->smer);
  scanf("%f", &s->prosek);
}

void ispisi(const STUDENT* s){
  printf("%s %s, %c, %.2f\n",s->ime, s->prezime, s->smer, s->prosek);
}

float najveci_prosek(STUDENT studenti[], int n){
  float m;
  int i;

  m = studenti[0].prosek;
  for(i=1;i<n;i++)
    if(m<studenti[i].prosek) 
       m=studenti[i].prosek; 
  return m;
}

STUDENT prvi_student_sa_najvecim_prosekom(STUDENT studenti[], int n, float m){
  STUDENT s;
  int i;
  for(i=0;i<n;i++)
    if(m == studenti[i].prosek){
     s = studenti[i];
     break;
    }
  return s;
}

int main(){
  STUDENT studenti[MAXST];
  int n, i, indeks;
  float max_prosek;
  STUDENT student_sa_max_prosekom;
  char smer;    

  scanf("%d", &n);
  if(n<0 || n>MAXST){
    printf("Nekorektan unos\n");
    return -1;
  }
  
  for(i=0; i<n; i++){
    printf("%d. student: ", i+1); 
    ucitaj(&studenti[i]);
    provera(studenti[i].smer);
  }

  getchar();
  scanf("%c", &smer);

  provera(smer);

  for(i=0;i<n;i++)
     if(studenti[i].smer == smer) 
        printf("%s %s\n",studenti[i].ime, studenti[i].prezime);

  max_prosek = najveci_prosek(studenti, n);  
  for(i=0;i<n;i++)
     if(studenti[i].prosek == max_prosek)
        ispisi(&studenti[i]);

  return 0;  
}

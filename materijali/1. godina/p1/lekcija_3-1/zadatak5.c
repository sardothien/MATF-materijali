/* Napisati program koji učitava karaktere sa standardnog
ulaza sve do kraja ulaza i izračunava koliko se puta u unetom
tekstu pojavila svaka od cifara, svako malo slovo i svako
veliko slovo. Ispisati broj pojavljivanja samo za karaktere
koji su se u unetom tekstu pojavili barem jednom. Uputstvo:
Za evidenciju broja pojavljivanja cifara, malih i velih slova
korisiti pojedinačne nizove. */

#include <stdio.h>
#include <ctype.h>

#define MAX_C 10
#define MAX_S 26

int main(){

 int c[MAX_C], m[MAX_S], v[MAX_S];
 char k;
 int i;
 
 for(i=0; i<MAX_C; i++){
  c[i]=0;
 }
 for(i=0; i<MAX_S; i++){
  m[i]=0;
  v[i]=0;
 }
 
 while((k=getchar()) != EOF){
  if(isdigit(k)){
   c[k-'0']++;
  }
  else if(islower(k)){
   m[k-'a']++;
  }
  else if(isupper(k)){
   v[k-'A']++;
  }
 }
 
 for(i=0; i<MAX_C; i++){
  if(c[i]>0){
    printf("%d: %d\n", i, c[i]);
  }
 }
 
 for(i=0; i<MAX_S; i++){
  if(m[i]>0){
    printf("%c: %d\n", i+'a', m[i]);
  }
 }
 
 for(i=0; i<MAX_S; i++){
  if(v[i]>0){
    printf("%c: %d\n", i+'A', v[i]);
  }
 }
 return 0;
}

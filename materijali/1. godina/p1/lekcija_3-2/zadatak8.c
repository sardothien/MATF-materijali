/* Napisati funkciju void interpunkcija(int* br_tacaka,
int* br_zareza) koja prebrojava tačke i zareze u tekstu
koji se unosi sa standardnog ulaza. Napisati program
koji testira napisanu funkciju. */

#include <stdio.h>
#include <ctype.h>

void interpunkcija(int* br_tacaka, int* br_zareza){
 char c; 
 
 while((c=getchar())!=EOF){
  if(c=='.'){
   (*br_tacaka)++;
  }
  if(c==','){
   (*br_zareza)++;
  }
 }
}

int main(){
 int br_tacaka=0, br_zareza=0;
 
 interpunkcija(&br_tacaka, &br_zareza);
 printf("Broj tacaka: %d\n", br_tacaka );
 printf("Broj zareza: %d\n", br_zareza);
 
 return 0;
}

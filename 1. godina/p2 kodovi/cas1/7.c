/* Napisati program koji ispisuje broj navedenih argumenata
komadne linije, a zatim i same argumente sa rednim brojevima. */

#include <stdio.h>

int main(int argc, char* argv[]){
 printf("%d\n", argc);
 
 int i;
 for(i=0; i<argc; i++){
  printf("%d. %s\n", i, argv[i]);
 }
 
 return 0;
}

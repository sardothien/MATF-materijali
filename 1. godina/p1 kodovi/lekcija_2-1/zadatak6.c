/* U prodavnici je organizovana akcija da svaki kupac dobije najjeftiniji od tri artikla za jedan dinar. Napisati program koji za unete cene tri artikla izračunava ukupnu cenu, kao i koliko dinara se uštedi zahvaljujući popustu. */

#include <stdio.h>

int main(){

  int a1, a2, a3, s=0, c=0;
  
  printf("Uneti cene tri artikla: ");
  scanf("%d%d%d", &a1, &a2, &a3);
  
  c=a1+a2+a3;
  
  if(a1<=a2 && a1<=a3 ){
      a1=1;
  }  
  if(a2<=a1 && a2<=a3 ){
      a2=1;
  }
  if(a3<=a1 && a3<=a2 ){
      a3=1;
  }
  
  s=a1+a2+a3;
  
  printf("Cena sa popustom: %d\n", s);
  printf("Usteda: %d\n", c-s);
    
  return 0;
}

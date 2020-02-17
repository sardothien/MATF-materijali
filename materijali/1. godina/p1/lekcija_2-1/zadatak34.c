/* Korisnik unosi tri cela broja: P , Q i R. Nakon toga unosi i dva karaktera, op1 i op2. Ovi karakteri predstavljaju operacije nad unetim brojevima i imaju naredno značenje:
• karakter k predstavlja logičku konjukciju
• karakter d predstavlja logičku disjunkciju
• karakter m predstavlja relaciju manje
• karakter v predstavlja relaciju veće
Program treba da sračuna vrednost izraza P op1 Q op2 R i da ga ispiše. */

#include <stdio.h>
#include <math.h>

int main(){

  int p, q, r, rez1, rez2;
  char op1, op2;
  
  scanf("%d%d%d", &p, &q, &r);
  getchar();
  scanf("%c %c", &op1, &op2);
  
  switch(op1){
  
   case 'k': rez1 = p && q;
             break;
   case 'd': rez1 = p || q;
             break;   
   case 'm': rez1 = p < q;
             break;
   case 'v': rez1 = p > q;
             break;
   default:  printf("-1\n");
             return -1;
  }


  switch(op2){
  
   case 'k': rez2 = rez1 && r;
             break;
   case 'd': rez2 = rez1 || r;
             break;
   case 'm': rez2 = rez1 < r;
             break;
   case 'v': rez2 = rez1 > r;
             break;
   default:  printf("-1\n");
             return -1;
  }

 printf("%d\n", rez2);

  return 0;
}

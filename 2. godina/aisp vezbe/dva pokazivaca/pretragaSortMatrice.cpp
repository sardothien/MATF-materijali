/* Svaka vrsta i svaka kolona matrice dimenzije m × n 
 * je sortirana neopadajuće. Napisati program koji u 
 * složenosti O(m + n) proverava da li matrica sadrži neki 
 * dati element. Prilagodi algoritam tako da u istoj složenosti
 * određuje broj pojavljivanja datog elementa. */

#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n, m;
  cin >> m >> n;
  
  int matr[m][n];
  for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
      cin >> matr[i][j];
    
  int x;
  cin >> x;
  
  int v = m-1, k = 0;
  while(v >= 0 && k < n){
    if(x < matr[v][k])
      v--;
    else if(x > matr[v][k])
      k++;
    else{
      cout << "Postoji" << endl;
      return 0;
    }
  }  
  
  cout << "Ne postoji" << endl;
  
  return 0;
}
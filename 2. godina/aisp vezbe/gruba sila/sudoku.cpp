/* Sudoku je zagonetka u kojoj se zahteva da se brojevi
 * od 1 do 9 rasporede po polju dimenzije 9 × 9 tako da 
 * se u svakoj vrsti, svakoj koloni i svakom od 9 kvadrata
 * dimenzije 3 × 3 nalaze različiti brojevi. Napisati funkciju
 * koja na osnovu nekoliko datih početnih vrednosti određuje 
 * da li je moguće ispravno popuniti Sudoku i ako jeste, određuje
 * bar jedno rešenje. */
#include<iostream>
#include<vector>
using namespace std;

const int n = 3;

bool konflikt(const vector<vector<int>>& m, int i, int j){
  for(int k = 0; k < n*n; k++)
    if(k != i && m[i][j] == m[k][j])
      return true;
    
  for(int k = 0; k < n*n; k++)
    if(k != j && m[i][j] == [i][k])
      return true;
  
  int x = i/n;
  int y = j/n;
  for(int k = x*n; k < (x+1)*n; k++)
    for(int l = y*n; k < (y+1)*n; l++)
      if(k != i && l != j && m[i][j] == m[k][l])
	return true;
      
  return false;
}

void sledeci(int& i, int& j){
  j++;
  
  if(j == n*n){
    j = 0;
    i++;
  }
}

bool sudoku(vector<vector<int>>& m, int i, int j){
  if(m[i][j] != 0){
    if(i == n*n - 1 && j == n*n - 1)
      return true;
    
    sledeci(i, j);
    return sudoku(m, i, j);
  }
  else{
    for(int k = 1; k <= n*n; k++){
      m[i][j] = k;
      if(!konflikt(m, i, j))
	if(sudoku(m, i, j))
	  return true;
    }
    
    m[i][j] = 0;
    return false;
  }
}

int main(){
  
  vector<vector<int>> m(n);

  // popunjavanje matrice

  cout << (sudoku ? "moguce" : "nije moguce") << endl;
  
  return 0;
}
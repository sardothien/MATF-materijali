/* Definisati proceduru koja nabraja i obrađuje sve 
 * permutacije skupa {1, 2,..., n}. */
#include<iostream>
#include<vector>
using namespace std;

void obradi(vector<int> permutacije){
  for(int i = 0; i < permutacije.size(); i++)
    cout << permutacije[i];
  cout << endl;
}

bool sledecaPermutacija(vector<int>& permutacija, int n){
  int i = n-2;  
  while(i >= 0 && permutacija[i] > permutacija[i+1])
    i--;
  
  if(i < 0)
    return false;
  
  int j = n-1;
  while(permutacija[j] < permutacija[i])
    j--;
  
  swap(permutacija[i], permutacija[j]);
  
  for(j = n-1, i++; i < j; i++, j--)
    swap(permutacija[i], permutacija[j]);
  
  return true;
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> permutacije(n);
  for(int i = 0; i < n; i++)
    permutacije[i] = i+1;
  
  do{
    obradi(permutacije);
  }while(sledecaPermutacija(permutacije, n));
  
  return 0;
}
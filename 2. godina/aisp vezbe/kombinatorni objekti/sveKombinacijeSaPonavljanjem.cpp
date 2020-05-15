/* Definisati proceduru koja nabraja i obrađuje sve kombinacije
 * sa ponavljanjem dužine k skupa {1, 2,..., n}, za k ≤ n. */
#include<iostream>
#include<vector>
using namespace std;

void obradi(vector<int> kombinacija){
  for(int i = 0; i < kombinacija.size(); i++)
    cout << kombinacija[i];
  cout << endl;
}

void obradiSveKombSaPonavljanjem(vector<int>& kombinacija, int i, int min, int max){
  int k = kombinacija.size();
  
  if(i == k){
    obradi(kombinacija);
    return;
  }
  
  if(min > max)
    return;
  
  kombinacija[i] = min;
  
  obradiSveKombSaPonavljanjem(kombinacija, i+1, min, max);
  obradiSveKombSaPonavljanjem(kombinacija, i, min+1, max);
}

int main(){
  
  int n, k;
  cin >> n >> k;
  
  vector<int> kombinacija(k);
  
  obradiSveKombSaPonavljanjem(kombinacija, 0, 1, n);
  
  return 0;
}
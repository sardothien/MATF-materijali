/* Definisati proceduru koja nabraja i obrađuje sve 
 * kombinacije bez ponavljanja dužine k skupa 
 * {1, 2,..., n}, za k ≤ n. */

#include<iostream>
#include<vector>
using namespace std;

void obradi(vector<int> kombinacija){
  for(int i = 0; i < kombinacija.size(); i++)
    cout << kombinacija[i];
  cout << endl;
}

void obradiSveKombinacije(vector<int>& kombinacija, int i, int n){
  int k = kombinacija.size();
  
  if(i == k){
    obradi(kombinacija);
    return;
  }
  
  int pocetak = i == 0 ? 1 : kombinacija[i-1]+1;
  int kraj = n + i - k + 1;
  
  for(int x = pocetak; x <= kraj; x++){
    kombinacija[i] = x;
    obradiSveKombinacije(kombinacija, i+1, n);
  }
}

int main(){
  
  int n, k;
  cin >> n >> k;
  
  vector<int> kombinacija(k);
  
  obradiSveKombinacije(kombinacija, 0, n);
  
  return 0;
}
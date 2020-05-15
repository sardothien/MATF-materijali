/* Množenje matrica dimenzije D1 × D2 i dimenzije D2 × D3
 * daje matricu dimenzije D1 × D3 i da bi se ono sprovelo 
 * potrebno je D1·D2·D3 množenja brojeva. Kada je potrebno
 * izmnožiti duži niz matrica, onda efikasnost zavisi od 
 * načina kako se te matrice grupišu (množenje je asocijativna 
 * operacija i dopušten je bilo koje grupisanje pre množenja.
 * Napiši program koji za dati niz brojeva D0, D1,..., Dn−1
 * određuje minimalni broj množenja brojeva prilikom 
 * množenja matrica dimenzija D0×D1, D1×D2,..., Dn−2×Dn−1. */
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int minBrojMnozenja(const vector<int>& dimenzije){
  int n = dimenzije.size();
  vector<vector<int>> dp(n);

  for(int i = 0; i < n; i++)
    dp[i].resize(n, 0);
  
  for(int k = 3; k <= n; k++)
    for(int l = 0, d = l + k - 1; d < n; l++, d++){
      dp[l][d] = numeric_limits<int>::max();
      for(int i = l+1; i <= d-1; i++){
	int broj = dp[l][i] + dp[i][d] + dimenzije[l] * dimenzije[i] * dimenzije[d];
	if(broj < dp[l][d])
	  dp[l][d] = broj;
      }
    }

  return dp[0][n-1];
}

int main(){
  int n;
  cin >> n;
  
  vector<int> dimenzije(n);
  for(int i = 0; i < n; i++)
    cin >> dimenzije[i];

  cout << minBrojMnozenja(dimenzije); 
  
  return 0;
}
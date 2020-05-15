/* Napisati program koji određuje dužinu najdužeg 
 * strogo rastućeg podniza (ne obavezno uzastopnih
 * elemenata) u datom nizu celih brojeva.
 * O(nlogn) */
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

void najduziRastuciPodniz(const vector<int>& a, vector<int>& podniz){
  int n = a.size();
  vector<int> dp(n);
  vector<int> prethodni(n, -1);
  int max = 0;

  for(int i = 0; i < n; i++){
    auto it = lower_bound(begin(dp), next(begin(dp), max), i, 
		  [a](int x, int y){
		    return a[x] < a[y];
		  });
    int d = distance(dp.begin(), it);
    dp[d] = i;
    if(d > 0)
      prethodni[i] = dp[d-1];
    if(d+1 > max)
      max = d+1;
  }
  
  podniz.resize(max);
  for(int k = max-1, i = dp[k]; k >= 0; k--, i = prethodni[i])
    podniz[k] = a[i];
}

int main(){
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  vector<int> podniz(n);
  
  najduziRastuciPodniz(a, podniz);
  
  for(int i = 0; i < n; i++)
    cout << podniz[i];
  cout << endl;  
  
  return 0;
}
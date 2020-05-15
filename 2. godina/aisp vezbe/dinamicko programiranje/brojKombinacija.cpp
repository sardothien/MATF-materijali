/* Napiši program koji određuje broj kombinacija
 * dužine k iz skupa od n elemenata. 
 * O(nk) */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n, k;
  cin >> n >> k;
  
  vector<int> dp(k+1);
  dp[0] = 1;
  
  for(int i = 1; i <= n; i++){
    if(i <= k)
      dp[i] = 1;
    for(int j = min(i-1, k); j > 0; j--)
      dp[j] += dp[j-1];
  }
  
  cout << dp[k] << endl;
  
  return 0;
}
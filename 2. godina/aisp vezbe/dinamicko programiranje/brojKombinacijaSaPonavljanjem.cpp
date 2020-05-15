#include<iostream>
#include<vector>
using namespace std;

int main(){ // O(nk)
  
  int n, k;
  cin >> n >> k;
  
  vector<int> dp(n+1, 1);
  dp[0] = 0;
  
  for(int i = 1; i <= k; i++)
    for(int j = 1; j <= n; j++)
      dp[j] += dp[j-1];
  
  cout << dp[n] << endl;
  
  return 0;
}
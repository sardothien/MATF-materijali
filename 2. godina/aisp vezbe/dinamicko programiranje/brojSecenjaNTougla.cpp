/* Odredi broj načina na koji se n-tougao može 
 * dijagonalama koje se ne presecaju raseći na 
 * trouglove. 
 * O(n^2) */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<int> dp(n);
  dp[0] = 1;
  
  int zbir = 0;
  
  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= i; j++)
      zbir += dp[j] + dp[i-j];
    dp[i] = zbir;
  }
  
  cout << dp[n] / n / 10 << endl;
  
  return 0;
}
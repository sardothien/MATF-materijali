/* Particija pozitivnog prirodnog broja n je predstavljanje 
 * broja n na zbir nekoliko pozitivnih prirodnih brojeva pri
 * čemu je redosled sabiraka nebitan. Napisati program koji 
 * određuje broj particija za dati prirodan broj n.
 * O(n^2) */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> dp(n+1, 0);
  dp[0] = 1;
  
  for(int smax = 1; smax <= n; smax++)
    for(int i = smax; i <= n; i++)
      dp[i] += dp[i - smax];
  
  cout << dp[n] << endl;
    
  return 0;
}
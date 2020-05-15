/* Dato je n predmeta čije su mase m0,..., mn−1 i ranac
 * nosivosti M. Napisati program koji određuje da li se
 * ranac može ispuniti do kraja nekim od n datih predmeta
 * (tako da je zbir masa predmeta jednak nosivosti ranca).
 * O(n + M) */
#include<iostream>
#include<vector>
using namespace std;

bool moze(vector<int>& masa, int ranac){
  int n = masa.size();
  vector<bool> dp(ranac+1, false);
  dp[0] = true;
  
  for(int i = 1; i <= n; i++)
    for(int j = ranac-masa[i-1]; j >= 0; j--)
      if(dp[j])
	dp[j + masa[i-1]] = true;
      
  return dp[ranac];
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> mase(n);
  for(int i = 0; i < n; i++)
    cin >> mase[i];
  
  int ranac;
  cin >> ranac;
  
  if(moze(mase, ranac))
    cout << "moze" << endl;
  else 
    cout << "ne moze" << endl;
  
  return 0;
}
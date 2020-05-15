/* Defisati funkciju koja određuje dužinu najduže 
 * zajedničke podniske (ne obavezno uzastopnih karaktera)
 * dve date niske. Na primer za niske ababc i babbca 
 * najduža zajednička podniska je babc. */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int najduziZajednickiPodniz(const string& s1, const string& s2){
  int n1 = s1.size(), n2 = s2.size();
  vector<vector<int>> dp(n1+1);

  for(int i = 0; i <= n1; i++)
    dp[i].resize(n2 + 1, 0);
  
  for(int i = 1; i <= n1; i++)
    for(int j = 1; j <= n2; j++){
      if(s1[i-1] == s2[j-1])
	dp[i][j] = dp[i-1][j-1] + 1;
      else
	dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
    }

  return dp[n1][n2];
}

int main(){
  
  string s1, s2;
  cin >> s1;
  cin >> s2;
  
  cout << najduziZajednickiPodniz(s1, s2) << endl;
  
  return 0;
}
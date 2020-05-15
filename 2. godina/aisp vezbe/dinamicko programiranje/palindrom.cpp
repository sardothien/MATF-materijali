/* Napisati program koji određuje dužinu najdužeg 
 * palindromskog podniza date niske (podniz se dobija
 * brisanjem karaktera polazne niske i čita se isto s 
 * leva na desno i s desna na levo). */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int najduziPalindrom(const string& s){
  int n = s.length();
  vector<int> dpp(n, 0);
  vector<int> dp(n, 1);

  for(int r = 1; r < n; r++){
    for(int p = 0; p + r < n; p++){
      int q = p + r;
      if(s[p] == s[q]){
	int tmp = dp[p];
	dp[p] = dpp[p+1] + 2;
	dpp[p] = tmp;
      }
      else{
	dpp[p] = dp[p];
	dp[p] = max(dp[p], dp[p+1]);
      }
    }
    dpp[n-r] = dp[n-r];
  }

  return dp[0];
}

int main(){
  string s;
  cin >> s;
  
  cout << najduziPalindrom(s) << endl;
  
  return 0;
}
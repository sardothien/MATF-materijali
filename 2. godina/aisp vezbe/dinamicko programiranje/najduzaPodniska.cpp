/* Defisati funkciju koja određuje dužinu najduže
 * zajedničke podniske uzastopnih karaktera dve date 
 * niske. Na primer za niske ababc i babbca najduža
 * zajednička podniska je ab. 
 * O(nm) */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int najduzaZajednickaPodniska(const string& s1, const string& s2) {
  int n1 = s1.size(), n2 = s2.size();
  vector<int> dp(n2+1, 0);
  
  int maxPodniska = 0;
  
  for (int i = 1; i <= n1; i++)
    for (int j = n2; j >= 0; j--) {
      if (s1[i-1] == s2[j-1])
	dp[j] = dp[j-1] + 1;
      else
	dp[j] = 0;
      if (dp[j] > maxPodniska)
	maxPodniska = dp[j];
    }
  
  return maxPodniska;
}

int main(){
  
  string s1, s2;
  cin >> s1;
  cin >> s2;
  
  cout << najduzaZajednickaPodniska(s1, s2) << endl;
  
  return 0;
}
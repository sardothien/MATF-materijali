/* Edit-rastojanje između dve niske se definiše u 
 * terminima operacija umetanja, brisanja i izmena 
 * slova prve reči kojima se može dobiti druga reč.
 * Svaka od ove tri operacije ima svoju cenu. Definisati 
 * program koji izračunava najmanju cenu operacija kojima 
 * se od prve niske može dobiti druga. */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int editRastojanje(const string& s1, const string& s2){
  int cenaUmetanja = 1, cenaBrisanja = 1, cenaIzmene = 1;
  int n1 = s1.size(), n2 = s2.size();
  
  vector<int> dp(n2 + 1);
  
  for(int j = 0; j <= n2; j++)
    dp[j] = j * cenaUmetanja;
  
  for(int i = 1; i <= n1; i++){
    int prethodni = dp[0];
    dp[0] = i * cenaBrisanja;
    for(int j = 1; j <= n2; j++){
      int tekuci = dp[j];
      if(s1[i-1] == s2[j-1])
	dp[j] = prethodni;
      else{
	int r1 = tekuci + cenaBrisanja;
	int r2 = dp[j-1] + cenaUmetanja;
	int r3 = prethodni + cenaIzmene;
	dp[j] = min({r1, r2, r3});
      }
      
      prethodni = tekuci;
    }
  }
  
  return dp[n2];
}

int main(){
  
  string s1, s2;
  cin >> s1 >> s2;
  
  cout << editRastojanje(s1, s2) << endl;
  
  return 0;
}
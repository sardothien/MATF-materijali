/* Tekst koji se sastoji samo od velikih slova engleske 
 * abecede je kodiran tako što je svako slovo zamenjeno
 * njegovim rednim brojem u abecedi. Međutim, pošto između
 * slova nije pravljen razmak, dekodiranje nije jednoznačno.
 * Napiši program koji određuje broj načina na koji je moguće
 * dekodirati uneti niz cifara. */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  string s;
  cin >> s;
  
  int n = s.length();
  
  long long dp2 = 1;
  long long dp1 = s[n-1] != '0';
  
  for(int i = n-2; i >= 0; i--){
    long long dp = 0;
    if(s[i] == '0')
      dp += dp1;
    if(10 * (s[i] - '0') + (s[i+1] - '0') <= 26)
      dp += dp2;
    
    dp2 = dp1;
    dp1 = dp;
  }
  
  cout << dp1 << endl;
  
  return 0;
}
/* Na raspolaganju imamo n novčića čiji su iznosi celi brojevi
 * m0,..., mn−1. Napisati program koji određuje minimalni broj
 * novčića pomoću kojih se može platiti dati iznos (svaki novčić
 * se može upotrebiti samo jednom). */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> novcici(n);
  for(int i = 0; i < n; i++)
    cin >> novcici[i];
  
  int iznos;
  cin >> iznos;
  
  vector<int> resenje;
  vector<vector<int>> dp;
  
  while(iznos > 0){
    if(dp[n-1][iznos] == dp[n][iznos])
      n--;
    else{
      resenje.push_back(novcici[n-1]);
      iznos -= novcici[n-1];
      n--;
    }
  }
  
  cout << n << endl;
  
  return 0;
}
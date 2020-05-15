/* Matrica sadrži prirodne brojeve. Koliki se najveći
 * zbir može postići ako se kreće iz gornjeg levog ugla
 * i u svakom koraku se kreće ili na susedno polje
 * desno, ili na susedno polje dole. */
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

#define MAX (256)

int maksZbir(const int M[MAX][MAX],int n){
  vector<int> dp(n);
  dp[0] = M[0][0];

  for(int k = 1; k < n; k++)
    dp[k] = dp[k-1] + M[0][k];
  
  for(int v = 1; v < n; v++)
    for(int k = 1; k < n; k++)
      dp[k] = max(dp[k] + M[v][k], dp[k-1] + M[v][k]);

  return dp[n-1];
}

int main(){
  int n;
  cin >> n;
  
  int M[MAX][MAX];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> M[i][j];

  cout << maksZbir(M, n) << endl; 
  
  return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX (100)

void maxKvadrat(int mat[MAX][MAX], int m, int n){
  int dp[n];
  int max = 0;
  
  for(int j = 0; j < n; j++){
    dp[j] = mat[0][j];
    if(dp[j] > max)
      max = dp[j];
  }
  
  int l = 1;
  for (int i = 1; i < m; i++) {
    int prethodni = dp[0];
    dp[0] = mat[i][0];
    if (dp[0] > max)
      max = dp[0];
    
    for (int j = 1; j < n; j++) {
      int tekuci = dp[j];
      if (mat[i][j] == 0)
	dp[j] = 0;
      else
	dp[j] = min({prethodni, tekuci, dp[j-1]}) + 1;
      if (dp[j] > max){
	max = dp[j];
	cout << (i-l) << " " << (j-l) << endl; 
	cout << (i - l + max)%n << " " << (max - l + 1) << endl;
	l--;
      }
      prethodni = tekuci;
    }
  }
}

int main(){ // O(n^2)
  int n;
  cin >> n;
  
  int mat[MAX][MAX];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> mat[i][j];
    
  maxKvadrat(mat, n, n);
  
  return 0;
}
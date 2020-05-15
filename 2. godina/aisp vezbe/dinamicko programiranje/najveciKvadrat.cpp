/* Data je pragougaona matrica koja sadrži samo 
 * nule i jedinice. Napiši program koji određuje 
 * dimenziju najvećeg kvadratnog bloka koji se 
 * sastoji samo od jedinica. 
 * O(n^2) */
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

#define MAX (1000)

int maxKvadrat(int A[MAX][MAX], int m, int n){
  int dp[MAX];
  int max = 0;
  
  for(int j = 0; j < n; j++){
    dp[j] = A[0][j];
    if(dp[j] > max)
      max = dp[j];
  }

  for(int i = 1; i < m; i++){
    int prethodni = dp[0];
    dp[0] = A[i][0];
    if(dp[0] > max)
      max = dp[0];
    for(int j = 1; j < n; j++){
      int tekuci = dp[j];
      if(A[i][j] == 0)
	dp[j] = 0;
      else
	dp[j] = min({prethodni, tekuci, dp[j-1]}) + 1;
      if(dp[j] > max)
	max = dp[j];
      prethodni = tekuci;
    }
  }

  return max;
}

int main(){
  int n, m;
  cin >> n >> m;
  
  int a[MAX][MAX];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> a[i][j];

  cout << maxKvadrat(a, m, n); 
  
  return 0;
}
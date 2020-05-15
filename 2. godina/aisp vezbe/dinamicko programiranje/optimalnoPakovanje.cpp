/* Ispred lifta čeka n ≤ 20 matematičara. Poznata 
 * je masa svakog od njih i ukupna nosivost lifta 
 * (svako pojedinačno može da stane u lift). Odrediti
 * minimalan broj vožnji potreban da se svi prevezu.*/
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int brojVoznji(const vector<int>& tezine, int nosivost){
  int n = tezine.size();
  vector<pair<int, int>> dp(1 << n);
  dp[0] = {1, 0};

  for(unsigned podskup = 1; podskup < (1<<n); podskup++){
    dp[podskup] = {n, nosivost};
    for(int i = 0; i < n; i++){
      if(podskup & (1 << i)){
	auto minI = dp[podskup ^ (1 << i)];
	if(p.second + tezine[i] <= nosivost)
	  minI.second += tezine[i];
	else{
	  minI.first++;
	  minI.second = tezine[i];
	}
	dp[podskup] = min(dp[podskup], minI);
      }
    }
  }

  return dp[(1<<n)-1].first;
}

int main(){
  int n;
  cin >> n;
  
  vector<int> tezine(n);  
  for(int i = 0; i < n; i++)
    cin >> tezine[i];
  
  double nosivost;
  cin >> nosivost;

  cout << brojVoznji(tezine, nosivost) << endl; 
  
  return 0;
}

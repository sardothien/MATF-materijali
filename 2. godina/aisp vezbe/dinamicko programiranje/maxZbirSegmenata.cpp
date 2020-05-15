/* Definisati efikasnu funkciju koja pronalazi najveći 
 * mogući zbir segmenta (podniza uzastopnih elemenata) 
 * datog niza brojeva. 
 * O(1) */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  int dp = 0;
  int rez = dp;
  
  for(int i = 1; i <= n; i++){
    dp = max(0, dp + a[i-1]);
    rez = max(rez, dp);
  }
  
  cout << rez << endl;
  
  return 0;
}
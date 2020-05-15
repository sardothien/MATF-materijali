/* Sortirani niz u kome su svi elementi različiti 
 * je rotiran za k mesta ulevo i time je dobijen 
 * ciklični niz koji zadovoljava uslov da je 
 * xk < xk+1 < ... < xn < x0 < ... < xk−1. Naći 
 * njegov najmanji element.
 * O(n) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int l = 0, d = n-1;
  
  while(l <= d){
    int s = l + (d-l)/2;
    if(niz[s] < niz[n-1])
      d = s-1;
    else
      l = s+1;
  }
  
  cout << niz[l] << endl;
  
  return 0;
}
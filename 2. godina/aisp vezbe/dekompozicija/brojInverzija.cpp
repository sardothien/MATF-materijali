/* Odredi koliko različitih parova elemenata 
 * u nizu je takvo da je prvi element strogo 
 * veći drugog. */
#include<iostream>
#include<vector>
using namespace std;

int brojInverzija(vector<int>& tmp, int l, int d, vector<int>& pom){
  if(l >= d)
    return 0;
  
  int s = l + (d-l)/2;
  int br = 0;
  
  br += brojInverzija(tmp, l, s, pom);
  br += brojInverzija(tmp, s+1, d, pom);
  
  int pl = l, pd = s+1, pb = 0;
  
  while(pl <= s && pd <= d){
    if(tmp[pl] <= tmp[pd])
      pom[pb++] = tmp[pl++];
    else{
      br += s - pl + 1;
      pom[pb++] = tmp[pd++];
    }
  }
  
  while(pl <= s)
    pom[pb++] = tmp[pl++];
  while(pd <= d)
    pom[pb++] = tmp[pd++];
  
  for(int i = l; i <= d; i++)
    tmp[i] = pom[i-l];
  
  return br;
}

int main(){
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  vector<int> tmp(n);
  vector<int> pom(n);  
  for(int i = 0; i < n; i++)
    tmp[i] = niz[i];
    
  cout << brojInverzija(tmp, 0, n-1, pom) << endl;  
  
  return 0;
}
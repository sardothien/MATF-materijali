/* Dat je skup pozitivnih brojeva. Napisati program
 * koji određuje koliko elemenata tog skupa ima zbir 
 * jednak datom pozitivnom broju. */
#include<iostream>
#include<vector>
using namespace std;

int brojPodskupova(vector<int>& niz, int zbir, int k){
  if(zbir == 0)
    return 1;
  
  if(k == niz.size())
    return 0;
  
  return brojPodskupova(niz, zbir - niz[k], k+1)
       + brojPodskupova(niz, zbir, k+1);
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int x;
  cin >> x;
  
  cout << brojPodskupova(niz, x, 0) << endl;
  
  return 0;
}
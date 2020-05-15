/* Definisati algoritam složenosti O(n) koji određuje
 * koliko parova elemenata na različitim pozicijama u 
 * nizu imaju razliku jednaku datom broju r > 0. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int brojParova(vector<int> &niz, int razlika, int i, int j, int n){
  
  if (j == n)
    return 0;
  if(niz[j] - niz[i] < razlika)
    return brojParova(niz, razlika, i, j+1, n);
  if(niz[j] - niz[i] > razlika)
    return brojParova(niz, razlika, i+1, j, n);
  
  return 1 + brojParova(niz, razlika, i+1, j+1, n);  
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int r;
  cin >> r;
  
  sort(begin(niz), end(niz));
  
  cout << brojParova(niz, r, 0, 1, n) << endl;  
  
  return 0;
}
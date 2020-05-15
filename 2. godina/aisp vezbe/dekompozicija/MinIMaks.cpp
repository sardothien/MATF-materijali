/* Pretpostavimo da se u nizu nalaze elementi koje je 
 * moguće upoređivati, ali čije je poređenje skupa operacija. 
 * Definisati funkciju koja efikasno određuje minimum i
 * maksimum tog niza. 
 * O(n) */

#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void minimax(const vector<int>& a, int l, int d, int &min, int& max){
  if(l == d){
    min = l;
    max = l;
  }
  else if(l + 1 == d){
    if(a[l] < a[d]){
      min = l;
      max = d;
    }
    else{
      min = d;
      max = l;
    }
  }
  else{
    int s = l + (d-l)/2;
    int minL, minD, maxL, maxD;
    
    minimax(a, l, s, minL, maxL);
    minimax(a, s+1, d, minD, maxD);
    
    min = a[minD] < a[minL] ? a[minD] : a[minL];
    max = a[maxD] > a[maxL] ? a[maxD] : a[maxL];
  }
}

int main(){
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int min = numeric_limits<int>::max();
  int max = 0;

  minimax(niz, 0, n-1, min, max);
  
  cout << min << " " << max << endl;
  
  return 0;
}
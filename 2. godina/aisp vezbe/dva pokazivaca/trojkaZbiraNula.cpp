/* Definisati algoritam složenosti O(n^2) koji 
 * određuje da li u datom sortiranom nizu dužine n 
 * postoji trojka elemenata čiji je zbir 0. */

#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int brTrojki = 0;
  
  for(int i = 0; i < n-2; i++){
    int l = i+1, d = n-1;
    while(l < d){
      if(niz[i] + niz[l] + niz[d] > 0)
	d--;
      else if(niz[i] + niz[l] + niz[d] < 0)
	l++;
      else{
	brTrojki++;
	l++;
	d--;
      }
    }
  }
  
  cout << brTrojki << endl; 
  
  return 0;
}
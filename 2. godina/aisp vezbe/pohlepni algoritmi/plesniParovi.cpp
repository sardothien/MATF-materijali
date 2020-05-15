/* Poznate su visine n momaka i n devojaka. Napisati 
 * program koji određuje koliko se najviše plesnih 
 * parova može formirati tako da je momak uvek
 * viši od devojke. */
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
  int n;
  cin >> n;

  vector<int> momci(n);
  for(int i = 0; i < n; i++)
    cin >> momci[i];
  
  vector<int> devojke(n);
  for(int i = 0; i < n; i++)
    cin >> devojke[i];

  sort(begin(momci), end(momci), greater<int>());
  sort(begin(devojke), end(devojke), greater<int>());

  int brojParova = 0;
  int m = 0, d = 0;
  while (true){
    while(d < n && momci[m] < devojke[d])
      d++;
    if(d >= n)
      break;
    brojParova++;
    m++;
    d++;
  }
  
  cout << brojParova << endl;

  return 0;
}
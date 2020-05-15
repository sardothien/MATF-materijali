/* Ljudi su dolazili i odlazili sa 
 * bazena i za svakog posetioca je 
 * poznato vreme dolaska i vreme odlaska
 * (pretpostavićemo da je čovek na bazenu 
 * u periodu oblika [a, b), tj. da ako jedan
 * čovek ode, a drugi dođe u apsolutno istom 
 * trenutku, da se broj ljudi ne menja). Koliko
 * je ljudi najviše bilo istovremeno na bazenu?
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<pair<int, int>> intervali(n);
  
  for(int i = 0; i < n; i++)
    cin >> intervali[i];
  
  
  vector<pair<int, int>> promene(2*n);
  
  // karakteristicni trenuci
  for(int i = 0; i < n; i++){
    promene[2*i] = make_pair(intervali[i].first, 1);
    promene[2*i+1] = make_pair(intervali[i].second, -1);
  }
  
  sort(begin(promene), end(promene));
  
  int trenutno = 0;
  int max = 0;
  int i = 0;
  
  while(i < n){
    trenutno += promene[i++].second;
    if(trenutno > max)
      max = trenutno;
  }
  
  cout << max << endl;  
  
  return 0;
}
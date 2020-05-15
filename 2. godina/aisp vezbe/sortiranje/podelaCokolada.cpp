/* Dato je n paketa čokolade i za svaki od 
 * njih je poznato koliko čokoladica sadrži. 
 * Svaki od k učenika uzima tačno jedan paket,
 * pri čemu je cilj da svi učenici imaju što 
 * približniji broj čokoladica. Kolika je najmanja
 * moguća razlika između onog učenika koji uzme 
 * paket sa najmanje i onog koji uzme paket sa 
 * najviše čokoladica.
 * O(nlogn) */
 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int i = 0; i < n; i++)
    cin >> a[i];
  
  sort(begin(a), end(a));
  
  int min = numeric_limits<int>::max();
  
  int k;
  cin >> k;
  
  for(int i = 0; i + k - 1 < n; i++){
    int razlika = a[i+k-1] - a[i];
    if(razlika < min)
      min = razlika;
  }
  
  cout << min << endl;
  
  return 0;
}
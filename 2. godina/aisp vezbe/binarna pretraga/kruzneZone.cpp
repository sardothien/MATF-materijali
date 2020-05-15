/* Kvalitet signala zavisi od udaljenosti 
 * tačke od predajnika. Prostor je podeljen 
 * u zone oblika kružnih prstenova, pri čemu
 * širine prstenova mogu biti međusobno različite. 
 * Napiši program koji učitava broj i širinu svih 
 * zona i za niz učitanih tačaka određuje zonu kojoj 
 * pripadaju (zone se broje od nule, ako je tačka na
 * granici dve zone smatra se da pripada unutrašnjoj, 
 * a ako ne pripada ni jednoj zoni ispisuje se -1). */

#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<cmath>
using namespace std;

void indeksiZona(const vector<double> &zone, const vector<pair<double, double>> &tacke,
  vector<int> &indeksi){
  
    vector<double> poluprecnici(zone.size());
    partial_sum(zone.begin(), zone.end(), poluprecnici.begin());

    for(int i = 0; i < tacke.size(); i++){
      int x = tacke[i].first, y = tacke[i].second;
      double r = sqrt(x*x + y*y);
      auto it = lower_bound(poluprecnici.begin(), poluprecnici.end(), r);
      if(it == poluprecnici.end())
	indeksi[i] = -1;
      else
	indeksi[i] = distance(poluprecnici.begin(), it);
    }
}

int main(){
  
  int n;
  cin >> n;
  
  vector<double> zone(n);
  for(int i = 0; i < n; i++)
    cin >> zone[i];
  
  vector<pair<double, double>> tacke(n);
  for(int i = 0; i < n; i++)
    cin >> tacke[i].first >> tacke[i].second;
  
  vector<int> indeksi(n);
  for(int i = 0; i < n; i++)
    cin >> indeksi[i];
  
  indeksiZona(zone, tacke, indeksi);
  
  for(int i = 0; i < n; i++)
    cout << indeksi[i] << " ";
  cout << endl;  
  
  return 0;
}
/* Dato je n tegova i za svaki teg je poznata njegova masa. 
 * Datim tegovima treba što preciznije izmeriti masu S. 
 * Napisati program koji određuje najmanja razlika pri 
 * takvom merenju. */
#include<iostream>
#include<vector>
using namespace std;

double merenje(vector<double>& tegovi, double masa, int k, 
		double trenutnaMasa, double preostalaMasa){
  
  if(k == tegovi.size())
    return abs(masa - trenutnaMasa);
  
  double minRazlika = merenje(tegovi, masa, k+1, trenutnaMasa, preostalaMasa-tegovi[k]);
  
  if(trenutnaMasa + preostalaMasa > masa - minRazlika && 
    trenutnaMasa + tegovi[k] < masa + minRazlika){
      double razlika = merenje(tegovi, masa, k+1, trenutnaMasa+tegovi[k], preostalaMasa-tegovi[k]);
      
      if(razlika < minRazlika)
	minRazlika = razlika;
  }
  
  return minRazlika;
}

int main(){
  
  int n;
  cin >> n;
  
  vector<double> tegovi(n);
  for(int i = 0; i < n; i++)
    cin >> tegovi[i];
  
  double masa;
  cin >> masa;
  
  double ukupnaMasa = 0.0;
  for(int i = 0; i < n; i++)
    ukupnaMasa += tegovi[i];
  
  cout << merenje(tegovi, masa, 0, 0.0, ukupnaMasa) << endl;
  
  return 0;
}
/* Sortirati niz intervala tako da budu 
 * sortirani po levom kraju, a ako im je 
 * levi kraj isti, onda po desnom kraju.
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
  int pocetak, kraj;
};

int main(){
  
  int n;
  cin >> n;
  
  vector<Interval> interval(n);
  for(int i = 0; i < n; i++)
    cin >> interval[i].pocetak >> interval[i].kraj;
  
  sort(begin(interval), end(interval), [](Interval &i1, Interval &i2){
    return i1.pocetak < i2.pocetak || (i1.pocetak == i2.pocetak && i1.kraj < i2.kraj); 
  });
  
  for(int i = 0; i < n; i++)
    cout << interval[i].pocetak << " " << interval[i].kraj << endl;
  
  return 0;
}
/* Definisati funkciju koja množi dva polinoma predstavljena 
 * vektorima svojih koeficijenata. Jednostavnosti radi 
 * pretpostaviti da su vektori dužine 2^k. */
#include<iostream>
#include<vector>
using namespace std;

vector<double> proizvod_polinoma(const vector<double>& p1,
				 const vector<double>& p2){
  int n = p1.size();
  vector<double> proizvod(2*n, 0);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      proizvod[i+j] += p1[i] * p2[j];

  return proizvod;
}

void odstampaj_polinom(vector<double> p){
  int n = p.size();
  cout << p[0];
  for(int i=1; i<n; i++)
    cout << " + " << p[i] << " * x^" << i;
  cout << endl;
}

vector<double> karacuba(const vector<double>& p1, const vector<double>& p2){
  int n = p1.size();
  if(n == 1)
    return vector<double>(1, p1[0] * p2[0]);

  vector<double> a(n / 2), b(n / 2);
  copy_n(begin(p1), n/2, begin(a));
  copy_n(next(begin(p1), n/2), n/2, begin(b));

  vector<double> c(n / 2), d(n / 2);
  copy_n(begin(p2), n/2, begin(c));
  copy_n(next(begin(p2), n/2), n/2, begin(d));

  vector<double> ac = karacuba(a, c);
  vector<double> bd = karacuba(b, d);

  for(int i = 0; i < n/2; i++)
    a[i] += b[i];

  for(int i = 0; i < n/2; i++)
    c[i] += d[i];

  vector<double> abcd = karacuba(a, c);

  for(int i = 0; i < n; i++)
    abcd[i] -= ac[i] + bd[i];

  vector<double> proizvod(2*n, 0.0);
  for(int i = 0; i < n; i++){
    proizvod[n + i] += bd[i];
    proizvod[n/2 + i] += abcd[i];
    proizvod[i] += ac[i];
  }

  return proizvod;
}

int main(){
  int n;
  cin >> n;
  
  vector<double> p1(n);
  
  for(int i=0; i<n; i++)
    cin >> p1[i];
  
  vector<double> p2(n);
  
  for(int i=0; i<n; i++)
    cin >> p2[i];
  
  odstampaj_polinom(p1);
  odstampaj_polinom(p2);
  
  vector<double> proizvod(2*n-1);
  proizvod = proizvod_polinoma(p1,p2);
  odstampaj_polinom(proizvod);
  
  vector<double> k_proizvod(2*n-1);
  k_proizvod = karacuba(p1,p2);
  odstampaj_polinom(k_proizvod);
  
  return 0;
}
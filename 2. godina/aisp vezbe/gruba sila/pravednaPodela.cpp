/* Dva brata žele da podele predmete koje imaju u kući, 
 * tako da podela bude što pravednija, tj. da apsolutna 
 * razlika između vrednosti svih predmeta koje su dobili 
 * bude minimalna. Napisati program koji određuje vrednost 
 * te razlike. */
#include<iostream>
#include<vector>
using namespace std;

double podela(const vector<double>& predmeti, int n,
	      double zbirPrvog, double zbirDrugog){
  if(n == 0)
    return abs(zbirPrvog - zbirDrugog);

  return min(podela(predmeti, n-1, zbirPrvog + predmeti[n-1], zbirDrugog),
	     podela(predmeti, n-1, zbirPrvog, zbirDrugog + predmeti[n-1]));
}

int main(){
  int n;
  cin >> n;
  
  vector<double> predmeti;
  
  for(int i=0; i<n; i++)
    cin >> predmeti[i];
  
  cout << podela(predmeti, n-1, predmeti[n-1], 0.0) << endl;
  
  return 0;
}
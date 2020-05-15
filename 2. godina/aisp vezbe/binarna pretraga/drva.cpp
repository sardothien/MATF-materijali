/* Drvoseča treba da naseče n metara drva. On ima 
 * testeru koja može da se podesi na određenu visinu 
 * i da poseče sve što je iznad te visine. Odredi
 * najvišu moguću visinu na koju može da podesi testeru 
 * tako da naseče dovoljno drva, ali ne više od toga. 
 * Poznat je broj i visina svakog drveta u metrima (celi
 * brojevi). Testera se može podešavati takođe sa 
 * preciznošću jednog metra. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> visina(n);
  
  for(int i = 0; i < n; i++)
    cin >> visina[i];
  
  int potrebno;
  cin >> potrebno;
  
  sort(visina.begin(), visina.end(), greater<int>());
  
  int naseceno = 0, k;
  
  for(k = 1; k < n; k++){
    naseceno += (visina[k-1] - visina[k]) * k;
    if(naseceno >= potrebno)
      break;
  }
  
  cout << visina[k] + (naseceno - potrebno) / k << endl;
    
  return 0;
}
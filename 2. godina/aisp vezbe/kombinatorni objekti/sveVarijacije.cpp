/* Definisati funkciju koja obrađuje sve varijacije sa 
 * ponavljanjem dužine k skupa {1,..., n}. */

#include<iostream>
#include<vector>
using namespace std;

void obradi(vector<int> varijacija){
  for(int i = 0; i < varijacija.size(); i++)
    cout << varijacija[i];
  cout << endl;
}

bool sledecaVarijacija(int n, vector<int>& varijacija){
  int i;
  int k = varijacija.size();
  
  for(i = k-1; i >= 0 && varijacija[i] == n; i--)
    varijacija[i] = 1;
  
  if(i < 0)
    return false;
  
  varijacija[i]++;
  
  return true;
}

int main(){
  
  int k, n;
  cin >> n >> k;
  
  vector<int> varijacija(k, 1);
    
  do{
    obradi(varijacija);
  }while(sledecaVarijacija(n, varijacija));
  
  return 0;
}
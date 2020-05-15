#include<iostream>
#include<vector>
using namespace std;

bool uslov(vector<int> varijacije){
  for(int i = 0; i < varijacije.size()-1; i++)
    if(varijacije[i] == 2 && varijacije[i+1] == 2)
      return false;
  return true;
}

void obradi(vector<int> varijacije){
  int br = 0;
  for(int i = 0; i < varijacije.size(); i++){
    if(varijacije[i] == 1)
      cout << 'c';
    else{
      cout << 'p';
      br++;      
    }
  }
  cout << " " << br << endl;  
}

bool sledecaVarijacija(vector<int>& varijacije, int n){
  int i;
  int k = varijacije.size();
  for(i = k-1; i >= 0 && varijacije[i] == n; i--)
    varijacije[i] = 1;
  
  if(i < 0)
    return false;
  
  varijacije[i]++;
  
  return true;
}

int main(){
  
  int n, k; // n = 2
  cin >> n >> k;
  
  vector<int> varijacije(k, 1);
  
  do{
    if(uslov(varijacije))
      obradi(varijacije);
  }while(sledecaVarijacija(varijacije, n)); 
  
  return 0;
}
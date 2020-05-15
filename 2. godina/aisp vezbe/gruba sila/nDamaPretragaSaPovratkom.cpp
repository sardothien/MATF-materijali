#include<iostream>
#include<vector>
using namespace std;

bool dameSeNapadaju(const vector<int>& dame, int k){
  for(int i = 0; i < k; i++){
    if(dame[i] == dame[k])
      return true;
    if(abs(k-i) == abs(dame[k] - dame[i]))
      return true;
  }

  return false;
}

void ispisi(const vector<int>& dame){
  if(!dameSeNapadaju(dame, 0)){
    for(int x : dame)
      cout << x << " ";
    cout << endl;
  }
}

void nDama(vector<int>& dame, int k){
  if(k == dame.size())
    ispisi(dame);
  else{
    for(int i = 0; i < dame.size(); i++){
      dame[k] = i;
      if(!dameSeNapadaju(dame, k))
	nDama(dame, k+1);
    }
  }
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> dame(n);
  for(int i=0; i<n; i++)
    permutacija[i] = i+1;

  nDama(dame, 0);  
  
  return 0;
}
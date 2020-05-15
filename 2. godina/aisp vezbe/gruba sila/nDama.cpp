#include<iostream>
#include<vector>
using namespace std;

bool napadajuSe(vector<int> dame){
  for(int i = 0; i < dame.size(); i++)
    for(int j = i+1; j < dame.size(); j++)
      if(abs(i-j) == abs(dame[i] - dame[j]))
	return true;
  
  return false;
}

void obradi(vector<int> dame){
  if(!napadajuSe(dame)){
    for(int d : dame)
      cout << d << " ";
    cout << endl;
  }
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> dame(n);
  for(int i = 0; i < n; i++)
    dame[i] = i+1;
  
  obradi(dame);
  
  return 0;
}
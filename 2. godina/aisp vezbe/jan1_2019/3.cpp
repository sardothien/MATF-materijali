#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool uslov(string s){
  int n = s.size();
  
  for(int i = 0; i < n-1; i++){
    int a = s[i] - '0';
    int b = s[i+1] - '0';
    if(a % 2 == b % 2)
      return false;
  }
  
  return true;
}

int main(){
  int n;
  cin >> n;
  
  string s;
  
  for(int i = 1; i <= n; i++)
    s += i + '0';
  
  do{
    if(uslov(s))
      cout << s << endl;
  }while(next_permutation(s.begin(), s.end()));

  return 0;
}
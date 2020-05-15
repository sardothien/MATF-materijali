/* Definisati funkciju koja obrađuje sve binarne zapise 
 * dužine n u kome se ne javljaju dve uzastopne jedinice. */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool sledecaVarijacija(string &s, int n){
  int i = n-1;
  
  while((i >= 0 && s[i] == '1') || (i > 0 && s[i-1] == '1'))
    s[i--] = '0';
  
  if(i < 0)
    return false;
  
  s[i] = '1';
  
  return true;
}

int main(){
  
  int n;
  cin >> n;
  
  string s(n, '0');
  
  do{
    cout << s << endl;
  }while(sledecaVarijacija(s, n));  
  
  return 0;
}
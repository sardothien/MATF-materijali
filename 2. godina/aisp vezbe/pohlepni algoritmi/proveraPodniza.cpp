/* Date su dve reči zapisane malim slovima. Napisati 
 * program kojim se proverava da li slova druge reči
 * čine podniz slova prve reči, tj. da li se druga
 * reč može dobiti izbacivanjem nekih slova (ne obavezno
 * susednih) iz prve reči. */
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool jePodniz(const string& s1, const string& s2){
  int i, j;
  for(i = 0, j = 0; j < s2.size(); i++, j++){
    i = s1.find(s2[j], i);
    if(i == string::npos)
      break;
  }

  return j == s2.size();
}

int main(){
  string s1, s2;
  cin >> s1;
  cin >> s2;
  
  cout << jePodniz(s1,s2) << endl;
    
  return 0;
}
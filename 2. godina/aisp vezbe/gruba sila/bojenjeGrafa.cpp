/* Za dati graf zadat listom svojih grana (parova čvorova)
 * napisati program koji proverava da li se taj graf može 
 * obojiti sa tri različite boje, tako da su svi susedni 
 * čvorovi obojeni različitim bojama. */
#include<iostream>
#include<vector>
using namespace std;

bool oboj(vector<vector<int>>& susedi, int cvor, vector<int> boje){
  int brCvorova = susedi.size();
  
  if(cvor >= brCvorova)
    return true;
  
  for(int boja = 1; boja <= 3; boja++){
    bool mozeBoja = true;
    for(int sused : susedi[cvor])
      if(boje[sused] == boja)
	mozeBoja = false;
    
    if(mozeBoja){
      boje[cvor] = boja;
      if(oboj(susedi, cvor+1, boje))
	return true;
    }
  }
  
  return false;
}

int main(){
  
  int n;
  cin >> n;
  
  vector<vector<int>> susedi(n);  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      cin >> susedi[i][j];
  
  vector<int> boje(3);
  
  int cvor = 0;
  while(cvor < n && susedi[cvor].size() == 0)
    boje[cvor] = 1;
  
  boje[cvor] = 1;
  boje[susedi[0][0]] = 2;
  
  if(oboj(susedi, cvor, boje))  
    cout << "true" << endl;
  else
    cout << "false" << endl;
  
  return 0;
}
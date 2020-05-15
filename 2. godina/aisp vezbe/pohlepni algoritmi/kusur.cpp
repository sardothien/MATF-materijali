/* U Srbiji se koriste apoeni od 1, 2, 5, 10, 20, 50, 100, 200, 500, 1000,
 * 2000 i 5000 dinara. Napiši program koji formira datih iznos dinara od 
 * što manjeg broja novčanica i novčića. */
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void stampajKusur(int iznos){
  vector<int> apoeni {500, 200, 100, 50, 20, 10, 5, 2, 1};
  while(iznos > 0){
    for(int apoen : apoeni)
      if(iznos >= apoen){
	cout << apoen << endl;
	iznos -= apoen;
	break;
      }
  }
}

int main(){
  int iznos;
  cin >> iznos;
  
  stampajKusur(iznos);
    
  return 0;
}
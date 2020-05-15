/* U datom nizu pozitivnih prirodnih brojeva naći sve
 * segmente (njihov početak i kraj) čiji je zbir jednak
 * datom pozitivnom broju (brojanje pozicija počinje 
 * od nule). */

#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int x;
  cin >> x;
  
  int i = 0, j = 0;
  int zbir = a[0];
  
  while(1){
    if(zbir < x){
      j++;
      if(j >= n)
	break;
      zbir += a[j];
    }
    else{
      if(zbir == x)
	cout << i << " " << j << endl;
      zbir -= a[i];
      i++;
    }
  }
    
  return 0;
}
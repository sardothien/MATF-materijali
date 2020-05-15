/* Napiši funkciju kojom se nabrajaju sve tročlane kombinacije 
 * bez ponavljanja elemenata skupa {1, 2,..., n}. */
#include<iostream>
#include<vector>
using namespace std;

void obradi(int podskup[]){
  for(int i = 0; i < 3; i++)
    cout << podskup[i];
  cout << endl;
}

void troclaneKombinacije(int n){
  int komb[3];
  
  for(int i = 1; i <= n-2; i++){
    komb[0] = i;
    for(int j = i+1; j <= n-1; j++){
      komb[1] = j;
      for(int k = j+1; k <= n; k++){
	komb[2] = k;
	obradi(komb);
      }
    }
  }
  
}

int main(){
  
  int n;
  cin >> n;
  
  troclaneKombinacije(n);
  
  return 0;
}
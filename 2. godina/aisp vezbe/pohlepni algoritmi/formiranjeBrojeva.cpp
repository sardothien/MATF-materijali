/* Od datog niza od n cifara (od 0 do 9) odrediti minimalnu moguću
 * sumu dva broja formirana od cifara datog niza. Sve cifre niza 
 * moraju biti iskorišćene onoliko puta koliko se pojavljuju. 
 * Na primer, za 5, 3, 0, 7, 4 dobija se 82 (tj. 35 + 047). */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minZbir(int cifre[], int n){
  sort(cifre, next(cifre, n));
  int a = 0, b = 0;

  for(int i = 0; i < n; i++){
    a = 10 * a + cifre[i];
    if(a > b)
      swap(a, b);
  }

  return a+b;
}

int main(){
  int n;
  cin >> n;
  
  int cifre[n];
  for(int i = 0; i < n; i++)
    cin >> cifre[i];
  
  cout << minZbir(cifre, n) << endl;
    
  return 0;
}
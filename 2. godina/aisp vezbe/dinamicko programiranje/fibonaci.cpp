/* Napisati program koji za dato n izračunava Fn , gde je
 * Fn Fibonačijev niz definisan pomoću F0 = 0, F1 = 1 i 
 * Fn = Fn−1 + Fn−2 , za n > 1. 
 * O(1) */
#include<iostream>
#include<vector>
using namespace std;

int main(){
  
  int n;
  cin >> n;
    
  if(n == 0 || n == 1){
    cout << n << endl;
    return 0;
  }
  
  int pp = 0;
  int p = 1;
  for(int i = 2; i <= n; i++){
    int f = pp + p;
    pp = p;
    p = f;
  }
  
  cout << p << endl;
  
  return 0;
}
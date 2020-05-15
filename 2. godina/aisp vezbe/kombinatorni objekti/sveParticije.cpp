/* Particija pozitivnog prirodnog broja n je predstavljanje 
 * broja n kao zbira nekoliko pozitivnih prirodnih brojeva
 * pri čemu je redosled sabiraka nebitan. Napisati program 
 * koji ispisuje sve particije datog broja n sortirane 
 * leksikografski. */
#include<iostream>
#include<vector>
using namespace std;

void obradi(vector<int> particija, int i){
  while(i > 0){
    cout << particija[i-1];
    i--;
  }
  cout << endl;
}

void obradiParticije(int n, int smax, vector<int>& particija, int i){
  
  if(n == 0)
    obradi(particija, i);
  else{
    if(smax == 0)
      return;
    
    obradiParticije(n, smax-1, particija, i);
    
    if(n >= smax){
      particija[i] = smax;
      obradiParticije(n-smax, smax, particija, i+1);
    }
  }
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> particija(n);
  for(int i=0; i<n; i++)
    particija[i] = i+1;
  
  obradiParticije(n, n, particija, 0);
  
  return 0;
}
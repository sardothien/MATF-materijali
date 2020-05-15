/* Dva gosta su došla u hotel i žele 
 * da odsednu u sobama koje su što
 * bliže jedna drugoj, da bi tokom 
 * večeri mogli da zajedno rade u jednoj
 * od tih soba. Ako postoji više takvih 
 * soba, oni biraju da budu što dalje od 
 * recepcije, tj. u sobama sa što većim 
 * rednim brojevima, kako im buka ne bi 
 * smetala. Ako je poznat spisak slobodnih
 * soba u tom trenutku, napiši program koji
 * određuje brojeve soba koje gosti treba
 * da dobiju.
 * O(nlogn) */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  
  int n;
  cin >> n;
  
  vector<int> sobe(n);  
  for(int i = 0; i < n; i++)
    cin >> sobe[i];
  
  sort(begin(sobe), end(sobe));
  
  int min = 0;
  
  for(int i = 1; i < n-1; i++)
    if(sobe[i+1] - sobe[i] <= sobe[min+1] - sobe[min])
      min = i;
    
  cout << sobe[min] << " " << sobe[min+1] << endl;
  
  return 0;
}
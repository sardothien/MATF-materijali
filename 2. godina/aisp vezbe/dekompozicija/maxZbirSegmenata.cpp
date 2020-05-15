/* Definisati efikasnu funkciju koja pronalazi najveći 
 * mogući zbir segmenta (podniza uzastopnih elemenata) 
 * datog niza brojeva.
 * O(n) */
#include<iostream>
#include<vector>
using namespace std;

int maksZbirSegmenta(const vector<int>& a, int l, int d, int& zbir, 
		    int& maks_zbir, int& maks_prefiks, int& maks_sufiks){

  if(l == d){
    zbir = maks_zbir = maks_prefiks = maks_sufiks = a[l];
    return zbir;
  }

  int s = l + (d - l) / 2;
  int zbir_levo, maks_zbir_levo, maks_sufiks_levo, maks_prefiks_levo;
  maksZbirSegmenta(a, l, s, zbir_levo, maks_zbir_levo, 
		   maks_prefiks_levo, maks_sufiks_levo);

  int zbir_desno, maks_zbir_desno, maks_sufiks_desno, maks_prefiks_desno;
  maksZbirSegmenta(a, s+1, d,zbir_desno, maks_zbir_desno,
		  maks_prefiks_desno, maks_sufiks_desno);

  zbir = zbir_levo + zbir_desno;
  maks_prefiks = max(maks_prefiks_levo, zbir_levo + maks_prefiks_desno);
  maks_sufiks = max(maks_sufiks_desno, maks_sufiks_levo + zbir_desno);
  maks_zbir = max({maks_zbir_levo, maks_zbir_desno,
		   maks_sufiks_levo + maks_prefiks_desno});

  return maks_zbir;
}

int main(){
  
  int n;
  cin >> n;
  
  vector<int> niz(n);
  for(int i = 0; i < n; i++)
    cin >> niz[i];
  
  int zbir, maks_zbir, maks_prefiks, maks_sufiks;
  
  cout << maksZbirSegmenta(niz, 0, n-1, zbir, maks_zbir, maks_prefiks, maks_sufiks) << endl;
  
  return 0;
}
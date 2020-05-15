/* Na pruzi se nalaze vagoni označeni brojevima od 1 do n, ali su
 * ispremetani. Potrebno je prebaciti ih na drugi kraj pruge u tako
 * da su poređani od 1 do n. Sa strane pruge nalaze se tri pomoćna 
 * koloseka na koji se privremeno mogu smeštati vagoni. Pruga sa 
 * pomoćnim kolosecima ima oblik ćiriličkog slova Š sa produženom 
 * donjom osnovom. */
#include <iostream>
#include <stack>
#include <queue>
#include <limits>
using namespace std;

int main(){
  queue<int> ulaz;
  int n;
  cin >> n;

  for(int i = 0; i < n; i++){
    int x;
    cin >> x;
    ulaz.push(x);
  }

  stack<int> s[3];
  for(int i = 0; i < 3; i++)
    s[i].push(numeric_limits<int>::max());

  int treba_da_izadje = 1;
  bool moze = true;

  while(treba_da_izadje <= n){
    bool izasao_sa_pomocnog = false;
    for(int i = 0; i < 3; i++){
      if(s[i].top() == treba_da_izadje){
	cout << "Sa koloseka " << i << " izlazi " << treba_da_izadje << endl;
	s[i].pop(); treba_da_izadje++;
	izasao_sa_pomocnog = true;
      }
    }
    if(izasao_sa_pomocnog)
      continue;
    int vagon = ulaz.front();
    ulaz.pop();
    if(vagon == treba_da_izadje){
      cout << "Sa ulaza izlazi " << treba_da_izadje << endl;
      treba_da_izadje++;
      continue;
    }
    int min = -1;
    for(int i = 0; i < 3; i++){
      if(vagon < s[i].top() && (min == -1 || s[i].top() < s[min].top()))
	min = i;
    }
    if(min == -1){
      moze = false;
      break;
    }
    cout << "Sa ulaza vagon " << vagon << " ide na kolosek " << min << endl;
    s[min].push(vagon);
  }

  if(moze)
    cout << "moze" << endl;
  else
    cout << "ne moze" << endl;

  return 0;
}
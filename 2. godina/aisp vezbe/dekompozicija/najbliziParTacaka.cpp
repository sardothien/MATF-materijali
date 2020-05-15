/* U ravni je zadato n tačaka svojim koordinatama. Napiši 
 * program koji određuje najmanje (Euklidsko) rastojanje 
 * među njima. 
 * O(nlogn) */
#include<iostream>
#include<vector>
using namespace std;

struct Tacka {
  int x, y;
};

double rastojanje(const Tacka& t1, const Tacka& t2){
  double dx = t1.x - t2.x;
  double dy = t1.y - t2.y;
  return sqrt(dx*dx + dy*dy);
}

bool porediX(const Tacka& t1, const Tacka& t2){
  return t1.x <= t2.x;
}

bool porediY(const Tacka& t1, const Tacka& t2){
  return t1.y <= t2.y;
}

double najblizeTacke(vector<Tacka>& tacke, int l, int r,
		     vector<Tacka>& pom){
  if(r - l + 1 < 4){
    double d = numeric_limits<double>::max();
    for(int i = l; i < r; i++)
      for(int j = i+1; j <= r; j++){
	double dij = rastojanje(tacke[i], tacke[j]);
	if(dij < d)
	  d = dij;
      }
    sort(next(begin(tacke), l), next(begin(tacke), r+1), porediY);
    return d;
  }

  int s = l + (r - l) / 2;
  double d2 = najblizeTacke(tacke, s+1, r);
  double d = min(d1, d2);

  merge(next(begin(tacke), l), next(begin(tacke), s+1),
	next(begin(tacke), s+1), next(begin(tacke), r+1),
	begin(pom), porediY);

  copy(begin(pom), end(pom), next(begin(tacke), l));

  double dl = tacke[s].x - d, dr = tacke[s].x + d;
  int k = 0;
  
  for(int i = l; i <= r; i++)
    if(dl <= tacke[i].x && tacke[i].x <= dr)
      pom[k++] = tacke[i];

  for(int j = i+1; j < pojas.size() && pojas[j].y - pojas[i].y < d; j++){
    double dij = rastojanje(pojas[i], pojas[j]);
    if(dij < d)
      d = dij;
  }

  return d;
}

double najblizeTacke(vector<Tacka>& tacke){
  vector<Tacka> pom(tacke.size());
  return najblizeTacke(tacke, 0, tacke.size() - 1, pom);
}

int main(){
  int n;
  cin >> n;
  
  vector<Tacka> tacke(n);
  
  for(int i=0; i<n; i++)
    cin >> tacke[i].x >> tacke[i].y;
  
  cout << najblizeTacke(tacke) << endl;
  
  return 0;
}
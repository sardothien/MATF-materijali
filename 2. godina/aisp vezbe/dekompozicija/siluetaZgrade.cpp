/* Sa broda se vide zgrade na obali velegrada. Duž obale
 * je postavljena koordinatna osa i za svaku zgradu se zna
 * pozicija levog kraja, visina i pozicija desnog kraja. Napisati
 * program koji izračunava siluetu grada. */

#include<iostream>
#include<vector>
using namespace std;

struct zgrada {
  int a, b, h;
  zgrada(int a = 0, int b = 0, int h = 0)
    : a(a), b(b), h(h) {
  }
};

struct promena {
  int x, h;
  promena(int x = 0, int h = 0)
    : x(x), h(h) {
  }
};

vector<promena> silueta;

vector<promena> silueta(const vector<zgrada>& zgrade, int l, int d){
  vector<promena> rezultat;

  if(l == d){
    rezultat.emplace_back(zgrade[l].a, zgrade[l].h);
    rezultat.emplace_back(zgrade[l].b, 0);
    return rezultat;
  }

  int s = l + (d - l) / 2;
  vector<promena> rezultat_l = silueta(zgrade, l, s);
  vector<promena> rezultat_d = silueta(zgrade, s+1, d);

  int ll = 0, dd = 0;
  int Hl = 0, Hd = 0;

  while(ll < rezultat_l.size() || dd < rezultat_d.size()){
    int x;
    if(ll == rezultat_l.size()){
      x = rezultat_d[dd].x; Hd = rezultat_d[dd].h;
      dd++;
    }
    else if(dd == rezultat_d.size()){
      x = rezultat_l[ll].x; Hl = rezultat_l[ll].h;
      ll++;
    }
    else{
      int xl = rezultat_l[ll].x;
      int xd = rezultat_d[dd].x;
      if(xl <= xd){
	x = xl; Hl = rezultat_l[ll].h;
	ll++;
      }
      else{
	x = xd; 
	Hd = rezultat_d[dd].h;
	dd++;
      }
    }

    int h = max(Hl, Hd);
    if(rezultat.size() > 0){
      int xb = rezultat.back().x, hb = rezultat.back().h;
      if(x == xb)
	rezultat.back().h = h;
      else if (h != hb)
	rezultat.emplace_back(x, h);
    }
    else
      rezultat.emplace_back(x, h);
  }

  return rezultat;
}

vector<promena> silueta(const vector<zgrada>& zgrade){
  return silueta(zgrade, 0, zgrade.size() - 1);
}

int main(){
  
  int n;
  cin >> n;
  
  vector<zgrada> zgrade;
  
  for(int i=0; i<n; i++)
    cin >> zgrade[i].a >> zgrade[i].b >> zgrade[i].h;
  
  cout << silueta(zgrade) << endl;  
  
  return 0;
}
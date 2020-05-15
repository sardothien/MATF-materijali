/* Napisati program koji određuje da li je u lavirintu 
 * moguće stići od starta do cilja. Lavirint je određen 
 * matricom karaktera (x označava zid kroz koji se ne može
 * proći i matrica je ograničena sa četiri spoljna zida, 
 * . označava slobodna polja, S označava start, a C označava 
 * cilj). Sa svakog polja dozvoljeno je kretanje u četiri 
 * smera (gore, dole, levo i desno). */
#include<iostream>
#include<vector>
using namespace std;

template<typename T> using Matrica = vector<vector<T>>;

Matrica<bool> napraviMatricu(int m, int n, bool value){
  Matrica<bool> mat;
  for(int i=0; i<m; i++){
    vector<bool> tekuce;
    for(int j=0; j<n; j++)
      tekuce.push_back(value);
    mat.push_back(tekuce);
  }

  return mat;
}

bool pronadjiPut(Matrica<bool>& lavirint, Matrica<bool>& posecen,
		 int x1, int y1, int x2, int y2){
  if(x1 == x2 && y1 == y2)
    return true;

  int pomeraj[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  
  for(int i = 0; i < 4; i++){
    int x = x1 + pomeraj[i][0], y = y1 + pomeraj[i][1];
    int m = lavirint.size(), n = lavirint[0].size();
    if(x < 0 || x >= m || y < 0 || y >= n)
      continue;
    if(lavirint[x][y] && !posecen[x][y]){
      posecen[x][y] = true;
      if(pronadjiPut(lavirint, posecen, x, y, x2, y2))
	return true;
    }
  }

  return false;
}

bool pronadjiPut(Matrica<bool>& lavirint, int x1, int y1, int x2, int y2){
  int m = lavirint.size(), n = lavirint[0].size();
  Matrica<bool> posecen = napraviMatricu(m, n, false);
  posecen[x1][y1] = true;
  return pronadjiPut(lavirint, posecen, x1, y1, x2, y2);
}

int main(){

  Matrica<bool> lavirint = {
	{false, false, false, false, false,
	false, false, false, false, false,
	false, false, false, false, false},
	{false, true, true, true, true,
	true, true, true, true, true,
	true, true, true, true, false},
	{false, true, false, false, false,
	false, false, false, false, false,
	false, false, false, false, false},
	{false, true, true, true, true,
	true, true, true, true, true,
	true, true, true, true, false},
	{false, false, false, false, false,
	false, false, false, false, false,
	false, false, false, true, false},
	{false, true, true, true, true,
	true, true, true, true, true,
	true, true, true, true, false},
	{false, true, false, false, false,
	false, false, false, false, true,
	false, false, false, false, false},
	{false, true, true, true, true,
	true, true, true, true, true,
	true, true, true, true, false},
	{false, false, false, false, false,
	false, false, false, false, false,
	false, false, false, false, false}};

  cout << "Put izmedju polja (1,1) i (7,13) ";
  cout << (pronadjiPut(lavirint, 1, 1, 7, 13) ? "" : "ne ");
  cout << "postoji" << endl;

  return 0;
}
/* Kuvar pravi jelo koje sadrži n raznih sastojaka.
 * Od svakog sastojka u kuhinji već ima određeni 
 * broj grama. Dostupan mu je određeni iznos novca i
 * za to može da kupuje mala ili velika pakovanja svakog
 * od sastojka (poznata je cena i gramaža svakog malog i 
 * svakog velikog pakovanja). Napisati program koji
 * određuje maksimalni broj porcija koje kuvar može da spremi. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int brojSastojaka;
int dostupanIznosNovca;
vector<int> potrebnoGrama, dostupnoGrama;
vector<int> maloGrama, maloCena;
vector<int> velikoGrama, velikoCena;

int ceilFrac(int a, int b) {
  return (a + b - 1) / b;
}

int minCena(int maloCena, int maloGrama, int velikoCena, int velikoGrama,
	    int potrebnoGrama){
  
  int najviseVelikih = ceilFrac(potrebnoGrama, velikoGrama);
  int min = najviseVelikih * velikaCena;

  for(int velikih = najviseVelikih - 1; velikih >= 0; velikih--){
    int potrebnaKolicinaMalih = potrebnaKolicina - velikih * velikaKolicina;
    int malih = ceilFrac(potrebnaKolicinaMalih, malaKolicina);
    int cena = velikih * velikaCena + malih * malaCena;
    if(cena < min)
      min = cena;
  }
  
  return min;
}

int mozeSeNapraviti(int brojPorcija){
  int ukupnaCena = 0;
  
  for(int i = 0; i < brojPorcija; i++){
    int potrebno = brojPorcija * potrebnoGrama[i] - postojiGrama[i];
    ukupnaCena += minCena(malaCena[i], malaKolicina[i],
		  velikaCena[i], velikaKolicina[i], potrebno);
  }

  return ukupnaCena <= dostupanIznosNovca;
}

int main(){
  int l = 0, d = 1;
  while(mozeSeNapraviti(d))
    d *= 2;
  
  while(l <= d){
    int s = l + (d - l) / 2;
    if(mozeSeNapraviti(s))
      l = s + 1;
    else
      d = s - 1;
  }
  
  cout << d << endl;
  
  return 0;
}
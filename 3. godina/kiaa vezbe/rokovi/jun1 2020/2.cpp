/* Zgrade u jednom gradu su oznacene brojevima od 0 do n-1
 * i povezane su jednosmernim ulicama cija je duzina poznata.
 * Zgrada obelezena brojem 0 je skola, a ostale su stambene
 * zgrade. Svako dete od kuce do skole roditelji voze najkracim
 * putem. Mali Iks bas bas bas mnogo ne voli skolu i zeli da
 * ubedi roditelje da se presele u zgradu koja je sto dalje od
 * nje. Napisati program koji odredjuje koja je to zgrada i koliko
 * je udaljena od skole. Sa standardnog ulaza se ucitavaju brojevi
 * n i m koji redom predstavljaju broj zgrada i broj ulica. Zatim
 * se u narednih m redova ucitavaju po tri prirodna broja x, y i d
 * koji predstavljaju ulicu od zgrade x do zgrade y duzine d. Na
 * standardni izlaz ispisati redni broj zgrade koja je najdalje od
 * skole i njenu udaljenost od skole, razdvojene razmakom. Ukoliko
 * postoji vise takvih zgrada, ispisati onu sa najmanjim rednim brojem. */

#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

struct Graf {
    int V;
    vector<vector<pair<int, int>>> lista_suseda;
    vector<bool> pronadjen_put;
    vector<int> rastojanja;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_suseda.resize(V);
    g.pronadjen_put.resize(V, false);
    g.rastojanja.resize(V, INT_MAX);
}

void dodaj_granu(Graf& g, int u, int v, int tezina){
    g.lista_suseda[u].push_back({v, tezina});
}

struct poredi {
    bool operator()(auto& p1, auto& p2){
        return p1.first > p2.first;
    }
};

void dijkstra(Graf& g, int u){

    priority_queue<pair<int, int>, vector<pair<int, int>>, poredi> hip;

    g.rastojanja[u] = 0;
    hip.push({g.rastojanja[u], u});

    pair<int, int> pom;

    while(!hip.empty()){
        pom = hip.top();
        hip.pop();

        if(g.pronadjen_put[pom.second])
            continue;

        g.pronadjen_put[pom.second] = true;

        for(pair<int, int>& sused : g.lista_suseda[pom.second]){
            if(g.rastojanja[sused.first] > g.rastojanja[pom.second] + sused.second){
                g.rastojanja[sused.first] = g.rastojanja[pom.second] + sused.second;
                hip.push({g.rastojanja[sused.first], sused.first});
            }
        }
    }

    int max_cvor = max_element(g.rastojanja.begin(), g.rastojanja.end()) - g.rastojanja.begin();
    cout << max_cvor << " " << g.rastojanja[max_cvor] << endl;
}

int main(){

    int n, m;
    cin >> n >> m;

    Graf g;
    inicijalizuj(g, n);

    int x, y, d;

    for(int i = 0; i < m; i++){
        cin >> x >> y >> d;
        dodaj_granu(g, y, x, d);
    }

    dijkstra(g, 0);
}

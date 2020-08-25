/* Za neusmereni graf G kazemo da je bipovezan ako vazi da
 * za bilo koja 2 cvora u i v postoje 2 razlicite putanje
 * kojima su oni povezani, tj ako iz u do v mozemo doci na
 * 2 nacina. Konstruisati algoritam koji za dati graf proverava
 * da li je bipovezan. Moze se pretpostaviti da ne postoje vise od
 * dva puta izmedju bilo koja dva cvora. */

/* Bipovezan - ako je povezan i nema artikulacionih tacaka */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> roditelji;
    vector<int> vremena;
    vector<int> min_vremena;
    vector<int> artikulacione_tacke;
    int vreme;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.roditelji.resize(V, -1);
    g.vremena.resize(V, -1);
    g.min_vremena.resize(V, -1);
    g.vreme = 0;
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
}

void dfs(Graf& g, int u){

    g.posecen[u] = true;
    g.vremena[u] = g.min_vremena[u] = g.vreme;
    g.vreme++;

    int deca = 0;

    auto pocetak = g.lista_susedstva[u].begin();
    auto kraj = g.lista_susedstva[u].end();

    while(pocetak != kraj){
        if(!g.posecen[*pocetak]){
            g.roditelji[*pocetak] = u;

            dfs(g, *pocetak);

            deca++;
            g.min_vremena[u] = min(g.min_vremena[*pocetak], g.min_vremena[u]);

            if(g.roditelji[u] == -1 && deca > 1)
                g.artikulacione_tacke.push_back(u);
            if(g.roditelji[u] != -1 && g.vremena[u] <= g.min_vremena[*pocetak])
                g.artikulacione_tacke.push_back(u);
        }
        else if(*pocetak != g.roditelji[u])
            g.min_vremena[u] = min(g.min_vremena[u], g.min_vremena[*pocetak]);

        pocetak++;
    }
}

void bipovezan(Graf& g){

    dfs(g, 0);

    if(g.artikulacione_tacke.size() > 0 || count_if(g.posecen.begin(), g.posecen.end(), [](bool je_posecen){
        return je_posecen == false; }) > 0)
        cout << "Ne" << endl;
    else
        cout << "Da" << endl;
}

int main(){

    Graf g;
    inicijalizuj(g, 5);

    dodaj_granu(g, 1, 0);
    dodaj_granu(g, 0, 2);
    dodaj_granu(g, 2, 1);
    dodaj_granu(g, 0, 3);
    dodaj_granu(g, 3, 4);

    bipovezan(g);

    return 0;
}

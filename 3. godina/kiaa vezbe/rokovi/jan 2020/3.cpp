/* Neka je dat usmereni graf sa *n* cvorova i *m* grana i 2
 * njegova cvora *u* i *v*. Odrediti broj disjunktnih puteva
 * izmedju *u* i *v*. Za 2 puta vazi da su disjunktna ukoliko
 * nemaju nijednu zajednicku granu. Sa standardnog ulaza se
 * unose brojevi *n* i *m*. Nakon toga se u narednih *m* linija
 * unose po 2 vrednosti koje predstavljaju grane grafa. Nakon toga
 * se unose jos 2 vrednosti koje predstavljaju cvorove *u* i *v*.
 * Na standardni izlaz ispisati broj disjunktnih puteva izmedju
 * ova 2 cvora. */

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<numeric>
using namespace std;

struct Graf {
    vector<vector<int>> lista_suseda;
    vector<int> roditelji;
    vector<vector<int>> tezine;
};

void inicijalizuj(Graf &g, const vector<vector<int>> &lista_suseda, const vector<int> &roditelji, const vector<vector<int>> &tezine){
    g.lista_suseda = lista_suseda;
    g.roditelji = roditelji;
    g.tezine = tezine;
}

void dodaj_granu(Graf &g, int u, int v, int tezina){
    g.lista_suseda[u].push_back(v);
    g.lista_suseda[v].push_back(u);
    g.tezine[u][v] = tezina;
}

int dfs(Graf &g, int u, int v){

    int rez = 0;

    fill(g.roditelji.begin(), g.roditelji.end(), -1);

    stack<int> dfs_stek;
    stack<int> min_tezina;

    dfs_stek.push(u);

    min_tezina.push(numeric_limits<int>::max());

    int trenutni_cvor, sused, tezina, n;

    while(!dfs_stek.empty()) {
        trenutni_cvor = dfs_stek.top();
        dfs_stek.pop();

        tezina = min_tezina.top();
        min_tezina.pop();

        if(trenutni_cvor == v){
            rez = tezina;
            break;
        }

        n = g.lista_suseda[trenutni_cvor].size();

        for(int i = 0; i < n; i++){
            sused = g.lista_suseda[trenutni_cvor][i];

            if(g.tezine[trenutni_cvor][sused] > 0 && g.roditelji[sused] == -1){
                dfs_stek.push(sused);
                min_tezina.push(min(tezina, g.tezine[trenutni_cvor][sused]));
                g.roditelji[sused] = trenutni_cvor;
            }
        }
    }

    if(rez > 0){
        trenutni_cvor = v;

        while(trenutni_cvor != u){
            g.tezine[g.roditelji[trenutni_cvor]][trenutni_cvor] -= rez;
            g.tezine[trenutni_cvor][g.roditelji[trenutni_cvor]] += rez;
            trenutni_cvor = g.roditelji[trenutni_cvor];
        }
    }

    return rez;
}

int ford_fulkerson(Graf &g, int u, int v){
    int max = 0, trenutno;

    while(true){
        trenutno = dfs(g, u, v);

        if(trenutno == 0)
            break;

        max += trenutno;
    }

    return max;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> lista_suseda;
    vector<int> roditelji;
    vector<vector<int>> tezine;

    lista_suseda.resize(n);
    roditelji.resize(n, -1);
    tezine.resize(n);

    for(auto &t : tezine)
        t.resize(n, 0);

    Graf g;
    inicijalizuj(g, lista_suseda, roditelji, tezine);

    int x, y;

    for(int i = 0; i < m; i++){
        cin >> x >> y;
        dodaj_granu(g, x, y, 1);
    }

    cin >> x >> y;

    cout << ford_fulkerson(g, x, y) << endl;

    return 0;
}

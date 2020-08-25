/* Neka je dato n gradova koji su povezani dvosmernim putevima. Desio 
 * se zemljotres i svi putevi su osteceni tako da gradovi nisu vise 
 * povezani. Potrebno je odrediti minimalnu cenu za popravku puteva
 * tako da svi gradovi opet budu povezani. Cena za popravku svakog od 
 * puteva je poznata. */

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

struct Graf {
    int V;
    vector<vector<pair<int,int>>> lista_susedstva;
    vector<int> roditelji;
    vector<int> grane;
    vector<bool> uDrvetu;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.uDrvetu.resize(V, false);
    g.roditelji.resize(V, -1);
    g.grane.resize(V, INT_MAX);
}

void dodaj_granu(Graf& g, int u, int v, int tezina){
    g.lista_susedstva[u].push_back(make_pair(v, tezina));
    g.lista_susedstva[v].push_back(make_pair(u, tezina));
}

int minGranaKojaNijeUkljucena(Graf& g){
    
    int min = INT_MAX;
    int min_indeks = -1;
    
    for(int i = 0; i < g.V; i++)
        if(g.uDrvetu[i] == false && g.grane[i] < min){
            min = g.grane[i];
            min_indeks = i;
        }
        
    return min_indeks;
}

void prim(Graf& g, int u){
    
    g.grane[u] = 0;
    
    int cvor;
    
    for(int i = 0; i < g.V-1; i++){
        cvor = minGranaKojaNijeUkljucena(g);
        g.uDrvetu[cvor] = true;
        
        for(int v = 0; v < g.V; v++){
            if(g.lista_susedstva[cvor][v].second && g.uDrvetu[v] == false && g.lista_susedstva[cvor][v].second < g.grane[v]){
                g.roditelji[v] = cvor;
                g.grane[v] = g.lista_susedstva[cvor][v].second;
            }
        }
    }
    
    int cena = 0;
    for(int i = 0; i < g.V; i++)
        if(i != u)
            cena += g.grane[i];
        
    cout << cena << endl;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 5);
    
    dodaj_granu(g, 0, 1, 1);
    dodaj_granu(g, 0, 2, 5);
    dodaj_granu(g, 0, 3, 10);
    dodaj_granu(g, 0, 4, 4);
    dodaj_granu(g, 1, 2, 2);
    dodaj_granu(g, 1, 4, 1);
    dodaj_granu(g, 2, 3, 4);
    
    prim(g, 0);
    
    return 0;
}

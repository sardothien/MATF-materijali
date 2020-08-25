/* Konstruisati algoritam koji za neusmereni graf G proverava
 * da li ima Ojlerov ciklus, Ojlerov put ili nijedno od ta dva. */

#include<iostream>
#include<vector>
using namespace std;

// treba dodati i proveru da li graf povezan (dfs)

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> stepen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.posecen.resize(V, false);
    g.stepen.resize(V, 0);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.lista_susedstva[v].push_back(u);
    g.stepen[u]++;
    g.stepen[v]++;
}

int ojler(Graf& g){
    
    int br = 0;
    
    for(int i = 0; i < g.V; i++)
        if(g.stepen[i] % 2 != 0)
            br++;
        
    if(br == 0)
        return 1; // ciklus
    else if(br == 2)
        return 2; // put
    else
        return 0; // nista
}

int main(){
    
    Graf g;
    inicijalizuj(g, 5);
    
//     dodaj_granu(g, 0, 1);
//     dodaj_granu(g, 1, 2);
//     dodaj_granu(g, 2, 0);
   
    dodaj_granu(g, 0, 1);
    dodaj_granu(g, 1, 2);
    dodaj_granu(g, 1, 4);
    dodaj_granu(g, 2, 3);
    
//     dodaj_granu(g, 0, 1);
//     dodaj_granu(g, 0, 2);
//     dodaj_granu(g, 0, 3);
//     dodaj_granu(g, 1, 2);
//     dodaj_granu(g, 1, 3);
//     dodaj_granu(g, 2, 3);
//     dodaj_granu(g, 2, 4);
//     dodaj_granu(g, 3, 4);
    
    if(ojler(g) == 1)
        cout << "Ima ciklus" << endl;
    else if(ojler(g) == 2)
        cout << "Ima put" << endl;
    else
        cout << "Nema ni ciklus ni put" << endl;
    
    return 0;
}

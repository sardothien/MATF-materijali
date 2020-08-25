/* Utvrditi da li u usmerenom tezinskom grafu G postoji ciklus
 * negativne tezine. Ciklus negativne tezine je ciklus za koji
 * vazi da je zbir tezina grana negativan. */

#include<iostream>
#include<vector>
using namespace std;

#define INF (9999)

struct Graf {
    int V;
    int **matrix;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.matrix = (int**)malloc(V * sizeof(int*));
    for(int i = 0; i < V; i++)
        g.matrix[i] = (int*)calloc(sizeof(int), V);

    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++){
            if(i == j)
                g.matrix[i][j] = 0;
            else
                g.matrix[i][j] = INF;
        }
}

void dodaj_granu(Graf& g, int u, int v, int tezina){
    g.matrix[u][v] = tezina;
}

void flojd_varsal(Graf& g){
    
    for(int k = 0; k < g.V; k++){
        for(int i = 0; i < g.V; i++){
            for(int j = 0; j < g.V; j++){
                if(g.matrix[i][j] > g.matrix[i][k] + g.matrix[k][j])
                    g.matrix[i][j] = g.matrix[i][k] + g.matrix[k][j];
            }
        }
    }
    
    for(int i = 0; i < g.V; i++){
        if(g.matrix[i][i] < 0){
            cout << "Postoji ciklus negativne tezine" << endl;
            return;
        }
    }
    
    cout << "Ne postoji ciklus negativne tezine" << endl;
}

int main(){
    
    Graf g;
    inicijalizuj(g, 4);
    
    dodaj_granu(g, 0, 1, 1);
    dodaj_granu(g, 1, 2, -1);
    dodaj_granu(g, 2, 3, -1);
    dodaj_granu(g, 3, 0, -1);
    
    flojd_varsal(g);
    
    return 0;
}

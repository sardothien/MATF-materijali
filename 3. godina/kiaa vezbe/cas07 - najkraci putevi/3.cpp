/* Neka je dat lavirint u vidu matrice. Svaka celija ima
 * odredjenu tezinu. Pronaci put od gornje leve do donje 
 * desne celije tako da ukupna suma vrednosti celija bude 
 * minimalna. */

#include<iostream>
#include<cstdlib>
#include<vector>
#include<climits>
#include<set>
using namespace std;

#define INF INT_MAX

class Celija {
public:
    // konstruktor
    Celija(){
        
    }
    
    // konstruktor 
    Celija(int i, int j, int rastojanje){
        this->i = i;
        this->j = j;
        this->rastojanje = rastojanje;
    }
    
    int i, j, rastojanje;
};

struct poredi {
    bool operator()(const Celija& c1, const Celija& c2){
        return c1.rastojanje < c2.rastojanje;
    }
};

struct Graf {
    int V;
    int **rastojanja;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.rastojanja = (int**)malloc(V * sizeof(int*));
    for(int i = 0; i < V; i++)
        g.rastojanja[i] = (int*)malloc(V * sizeof(int));
    
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            g.rastojanja[i][j] = INF;
}

void dijkstra(Graf& g, int lavirint[][5], int n){
    
    // koristimo set umesto min-heap
    set<Celija, poredi> set;
    
    // pocetni cvor
    Celija pom;
    pom.i = 0;
    pom.j = 0;
    pom.rastojanje = lavirint[0][0];
    
    set.insert(pom);
    
    g.rastojanja[0][0] = pom.rastojanje;
    
    while(!set.empty()){
        // prvi element iz skupa
        pom = *set.begin();
        set.erase(set.begin());
        
        // element iznad
        if(pom.i - 1 >= 0 && g.rastojanja[pom.i-1][pom.j] > g.rastojanja[pom.i][pom.j] + lavirint[pom.i-1][pom.j]){
            if(g.rastojanja[pom.i-1][pom.j] != INF)
                set.erase(set.find(Celija(pom.i-1, pom.j, g.rastojanja[pom.i-1][pom.j])));
            
            g.rastojanja[pom.i-1][pom.j] = g.rastojanja[pom.i][pom.j] + lavirint[pom.i-1][pom.j];
            set.insert(Celija(pom.i-1, pom.j, g.rastojanja[pom.i-1][pom.j]));
        }
        // element ispod
        if(pom.i + 1 < n && g.rastojanja[pom.i+1][pom.j] > g.rastojanja[pom.i][pom.j] + lavirint[pom.i+1][pom.j]){
            if(g.rastojanja[pom.i+1][pom.j] != INF)
                set.erase(set.find(Celija(pom.i+1, pom.j, g.rastojanja[pom.i+1][pom.j])));
            
            g.rastojanja[pom.i+1][pom.j] = g.rastojanja[pom.i][pom.j] + lavirint[pom.i+1][pom.j];
            set.insert(Celija(pom.i+1, pom.j, g.rastojanja[pom.i+1][pom.j]));
        }
        // element levo
        if(pom.j - 1 >= 0 && g.rastojanja[pom.i][pom.j-1] > g.rastojanja[pom.i][pom.j] + lavirint[pom.i][pom.j-1]){
            if(g.rastojanja[pom.i][pom.j-1] != INF)
                set.erase(set.find(Celija(pom.i, pom.j-1, g.rastojanja[pom.i][pom.j-1])));

            g.rastojanja[pom.i][pom.j-1] = g.rastojanja[pom.i][pom.j] + lavirint[pom.i][pom.j-1];
            set.insert(Celija(pom.i, pom.j-1, g.rastojanja[pom.i][pom.j-1]));
        }
        // element desno
        if(pom.j + 1 < n && g.rastojanja[pom.i][pom.j+1] > g.rastojanja[pom.i][pom.j] + lavirint[pom.i][pom.j+1]){
            if(g.rastojanja[pom.i][pom.j+1] != INF)
                set.erase(set.find(Celija(pom.i, pom.j+1, g.rastojanja[pom.i][pom.j+1])));

            g.rastojanja[pom.i][pom.j+1] = g.rastojanja[pom.i][pom.j] + lavirint[pom.i][pom.j+1];
            set.insert(Celija(pom.i, pom.j+1, g.rastojanja[pom.i][pom.j+1]));
        }
    }
    
    cout << g.rastojanja[n-1][n-1] << endl;
}


int main(){
    
    Graf g;
    inicijalizuj(g, 5);

    int lavirint[5][5] = {
            { 31, 100, 65, 12, 18 },
            { 10, 13, 47, 157, 6 },
            { 100, 113, 174, 11, 33 },
            { 88, 124, 41, 20, 140 },
            { 99, 32, 111, 41, 20 }
    };

    dijkstra(g, lavirint, 5);
    
    return 0;
}

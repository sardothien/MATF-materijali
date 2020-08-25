/* Student da bi mogao izaci na ispite koje je zeleo da 
 * polaze mora da obezbedi saglasnost profesora da je 
 * pratio njihova predavanja. Ali, neki profesori daju 
 * saglasnost samo ako student je pribavio saglasnost od 
 * profesora cija predavanja su preduslov za razumevanje 
 * njegovog predmeta. U prvoj liniji standardnog ulaza dat 
 * je broj profesora N (0<N<101) od kojih student trazi potpise.
 * U narednih N redova date su potrebne informacije tako da prvi
 * broj K u liniji I+1 predstavlja broj profesora čiji potpisi su
 * preduslov za potpis profesora I. Narednih K brojeva oznacavaju
 * te profesore. Ako se ne mogu prikupiti potpisi svih profesora, 
 * onda na standardni izlaz treba ispisati poruku NE, a ako se 
 * mogu prikupiti svi potpisi onda ispisati poruku DA u 1. red 
 * standardnog izlaza, a u narednih N linija ispisati redosled 
 * prikupljanja potpisa. */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> ulazni_stepen;
};

void inicijalizuj(Graf& g, int V){
    g.V = V;
    g.lista_susedstva.resize(V);
    g.ulazni_stepen.resize(V, 0);
}

void dodaj_granu(Graf& g, int u, int v){
    g.lista_susedstva[u].push_back(v);
    g.ulazni_stepen[v]++;
}

bool topolosko_sortiranje(Graf& g, vector<int>& rezultat){
        
    queue<int> cvorovi;
    
    for(int i = 0; i < g.V; i++)
        if(g.ulazni_stepen[i] == 0)
            cvorovi.push(i);
        
    int pom;
    
    while(!cvorovi.empty()){
        pom = cvorovi.front();
        cvorovi.pop();
        
        rezultat.push_back(pom);
        
        for(int cvor : g.lista_susedstva[pom]){
            g.ulazni_stepen[cvor]--;
            if(g.ulazni_stepen[cvor] == 0)
                cvorovi.push(cvor);
        }
    }
    
    if(rezultat.size() == g.V)
        return true;
    else
        return false;
}

int main(){
    
    int n, k, x;
    cin >> n;
    
    Graf g;
    inicijalizuj(g, n);
    
    for(int i = 0; i < n; i++){
        cin >> k;
        
        for(int j = 0; j < k; j++){
            cin >> x;
            dodaj_granu(g, x-1, i);
        }
    }
    
    vector<int> rezultat;
    
    if(topolosko_sortiranje(g, rezultat)){
        cout << "DA" << endl;
        for(int i = 0; i < n; i++)
            cout << rezultat[i] << " ";
        cout << endl;
    }
    else
        cout << "NE" << endl; 
    
    
    return 0;
}

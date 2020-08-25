/* Asistent KIAA-e želi studentima da da zadatke za ispit. To će uraditi 
 * kroz jednu igru. Pravila igre su sledeća:     
    1. Asistent kaže zadatke jednom studentu.
    2. Asistent numeriše studente i sebe rednim brojevima i određuje ko
       sa kim sme međusobno da komunicira.
    3. Svi studenti koji smeju da komuniciraju moraju da iskomuniciraju
       tačno jednom.
    4. Na kraju poslednji student mora da ponovi asistentu zadatke.
    5. Ukoliko studenti uspeju da iskomuniciraju i kažu asistentu zadatke
       ti zadaci ostaju za ispit, inače se smišljaju novi duplo teži zadaci.
    6. Studenti se dogovaraju i kažu asistentu da li prihvataju igru ili ne.
    Sa standardnog ulaza se unose brojevi N i M koji predstavlja broj studenata 
    (asistent je uračunat), kao i broj komunikacija koje će biti određene. 
    Nakon toga se u narednih M linija unose po 2 broja koja govore o tome ko 
    sa kim sme da komunicira. Na standardni izlaz ispisati "DA" ukoliko 
    studenti treba da prihvate, a "NE" u suprotnom.
    Može se pretpostaviti da nijedan student neće biti izuzet iz komunikacije. */

#include<iostream>
#include<vector>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<int> stepen;
    vector<bool> posecen;
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

int broj_neparnih(Graf& g){
    int br = 0;
    
    for(int i = 0; i < g.V; i++){
        if(g.stepen[i] % 2)
            br++;
    }
    
    return br;
}

bool ojlerov(Graf& g){
    int brN = broj_neparnih(g); 
    
    if(brN != 0)
        return false;
    else
        return true;
}

int main(){
    
    int n, m;
    cin >> n >> m;
    
    Graf g;
    inicijalizuj(g, n);
    
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        dodaj_granu(g, u, v);
    }
    
    if(ojlerov(g))
        cout << "DA" << endl;
    else
        cout << "NE" << endl;
    
    return 0;
}

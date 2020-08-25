/* Vodja Kubanske mafije Antonio Montana (Scarface), Toni se zamerio
 * veoma opasnom čoveku, Maniju Riberi. Ipak, čak ni Ribera ne može 
 * direktno da dodje do Tonija i likvidira ga, zato ima plan da
 * nadje krticu unutar Tonijeve organizacije i to iskoristi kao svoju 
 * prednost. S obzirom da zna kako funkcioniše Kubanska mafija smislio
 * je plan kako da pronadje članove iste koji bi mogli da budu krtice.
 * Način organizacije je sledeći: Toni kao šef je u komunikaciji samo 
 * sa najbližim saradnicima. Ljudi na nižim nivoima (pozicijama) ne 
 * mogu da komuniciraju sa najuticajnijim članovima, već to rade preko
 * posrednika. Kandidati za krticu su oni ljudi čije reči Toni ne može
 * da proveri iz više izvora, tj ljudi koji su jedini posrednici na 
 * odredjenom nivou hijerarhije. Ukoliko oni daju pogrešne informacije 
 * Ribera će biti u prednosti u odnosu na Tonija i imaće šansu da ga
 * ubije. Medjutim, Toni je saznao za Riberin plan i želi da sazna ko 
 * su potencijalne krtice i da porazgovara sa njima. U prvoj liniji 
 * standardnog ulaza se unosi broj n, broj članova Kubankse mafije. 
 * Zatim se unosi broj k, a u narednih k linija se unose po dve 
 * celobrojne vrednosti koje govore o tome ko sa kim može da komunicira. 
 * U jednoj liniji na standardnom izlazu ispisati sve one članove mafije 
 * (njihove redne brojeve) koji su potencijalne krtice i na koje bi Toni 
 * trebalo da obrati pažnju. Članove ispisati u rastućem poretku. Složenost
 * algoritma treba da bude O(n+k). */

#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct Graf {
    int V;
    vector<vector<int>> lista_susedstva;
    vector<bool> posecen;
    vector<int> roditelji;
    vector<int> vremena;
    vector<int> min_vremena;
    set<int> artikulacione_tacke;
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
                g.artikulacione_tacke.insert(u);
            if(g.roditelji[u] != -1 && g.vremena[u] <= g.min_vremena[*pocetak])
                g.artikulacione_tacke.insert(u);
        }
        else if(*pocetak != g.roditelji[u]){
            g.min_vremena[u] = min(g.min_vremena[u], g.vremena[*pocetak]);
        }
        
        pocetak++;
    }
    
}

void nadji_artikulacione_tacke(Graf& g){
    dfs(g, 0);
    
    for(int x : g.artikulacione_tacke)
        cout << x << " ";
    cout << endl;
}

int main(){
    
    int n, k;
    cin >> n >> k;
    
    Graf g;
    inicijalizuj(g, n);
    
    int u, v;
    
    for(int i = 0; i < k; i++){
        cin >> u >> v;
        dodaj_granu(g, u, v);
    }
    
    nadji_artikulacione_tacke(g);
    
    return 0;
}

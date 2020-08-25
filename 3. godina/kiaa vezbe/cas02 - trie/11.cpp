/* DNK sekvence se predstavljaju niskama koje se sastoje od 
 * karaktera c, t, a, g. U programu se odrzava skup podsekvenci 
 * jedne date genetske sekvence. Program podrzava tri operacije: 
 * ubacivanje podsekvence u skup, izbacivanje podsekvence iz skupa
 * i ispitivanje da li se podsekvenca nalazi u skupu. */
// pomocu trie

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    bool krajKljuca = false;
    unordered_map<char, cvor*> grane;
};

void ubaci(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        drvo->krajKljuca = true;
        return;
    }
    
    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        drvo->grane[w[i]] = new cvor();
    
    ubaci(drvo->grane[w[i]], w, i+1);
}

cvor* ubaci(cvor* drvo, string& w){
    if(drvo == nullptr)
        drvo = new cvor();
    
    ubaci(drvo, w, 0);
    
    return drvo;
}

bool izbaci(cvor* drvo, const string& w, int i){
    if(drvo == nullptr)
        return true;
    
    if(i == w.size())
        drvo->krajKljuca = false;
    else{
        auto it = drvo->grane.find(w[i]);
        if(it != drvo->grane.end() && izbaci(it->second, w, i+1))
            drvo->grane.erase(it);
    }
    
    if(!drvo->krajKljuca && drvo->grane.size() == 0){
        delete drvo;
        return true;
    }
    else
        return false;
}

cvor* izbaci(cvor* drvo, const string& w){
    if(izbaci(drvo, w, 0))
        return nullptr;
    else
        return drvo;
}

bool sadrzi(cvor* drvo, const string& w, int i){
    if(drvo == nullptr)
        return false;
    
    if(i == w.size())
        return drvo->krajKljuca;
    
    auto it = drvo->grane.find(w[i]);
    if(it != drvo->grane.end())
        return sadrzi(drvo->grane[w[i]], w, i+1);
    
    return false;
}

int main(){
    
    // broj upita
    int n;
    cin >> n;
    
    cvor* drvo = nullptr;
    
    for(int i = 0; i < n; i++){
        string naredba, niska;
        cin >> naredba >> niska;
        
        if(naredba == "ubaci")
            drvo = ubaci(drvo, niska);
        else if(naredba == "izbaci")
            drvo = izbaci(drvo, niska);
        else if(naredba == "trazi"){
            if(sadrzi(drvo, niska, 0))
                cout << "da" << endl;
            else 
                cout << "ne" << endl;
        }
    }    
    
    return 0;
}

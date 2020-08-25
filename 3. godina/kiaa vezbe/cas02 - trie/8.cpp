/* Implementirati autocomplete funkcionalnost. Neka je dat recnik 
 * podrzanih reci i jedna rec (prefiks). Naci sve reci koje pocinju
 * datom reci (prefiksom). */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    string rec = "";
    bool krajKljuca = false;
    unordered_map<char, cvor*> grane;
};

void umetni(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        drvo->rec = w;
        drvo->krajKljuca = true;
        return;
    }
    
    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        drvo->grane[w[i]] = new cvor();
    
    umetni(drvo->grane[w[i]], w, i+1);
}

cvor* autocomplete(cvor* drvo, string& prefiks, int i){
    if(i == prefiks.size())
        return drvo;
    
    auto it = drvo->grane.find(prefiks[i]);
    if(it == drvo->grane.end())
        return nullptr;
    
    return autocomplete(drvo->grane[prefiks[i]], prefiks, i+1);
}

void ispisi(cvor* drvo){
    if(drvo->krajKljuca)
        cout << drvo->rec << endl;
    
    auto pocetak = drvo->grane.begin();
    auto kraj = drvo->grane.end();
    
    while(pocetak != kraj){
        ispisi(pocetak->second);
        pocetak++;
    }
}

int main(){
    
    vector<string> reci = {
        "ana", "anica", "anicin", "anin", "anamarija",
        "anastasija", "anastasijin", "anamarijin"
    };
    
    cvor* drvo = new cvor();
    
    for(auto s : reci)
        umetni(drvo, s, 0);
    
    string prefiks = "ana";
    
    cvor* tmp = autocomplete(drvo, prefiks, 0);
    
    ispisi(tmp);
    
    return 0;
}

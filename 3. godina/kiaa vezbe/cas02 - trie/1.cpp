/* Kreirati strukturu za predstavljanje cvora prefiksong 
 * stabla. Napisati funkcije za umetanje reci u stablo i 
 * proveru da li se data rec nalazi u stablu. */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    bool krajKljuca = false;
    unordered_map<char, cvor*> grane;
};

void umetni(cvor* drvo, const string &w, int i){
    if(i == w.size()){
        drvo->krajKljuca = true;
        return;
    }
    
    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        drvo->grane[w[i]] = new cvor();
    
    umetni(drvo->grane[w[i]], w, i+1);
}

bool nadji(cvor* drvo, const string& w, int i){
    if(i == w.size())
        return drvo->krajKljuca;
    
    auto it = drvo->grane.find(w[i]);
    if(it != drvo->grane.end())
        return nadji(it->second, w, i+1);
    
    return false;
}

int main(){
    
    vector<string> reci = {
        "cod", "coder", "coding", "codecs"
    };
    
    cvor* drvo = new cvor();
    
    for(auto s : reci)
        umetni(drvo, s, 0);
    
//     vector<string> reci_novo = {
//         "cod", "coders", "coding", "codecs"
//     };
    
    vector<string> reci_novo = {
        "", "a", "d", "ananas", "marko", "ptica"
    };
    
    for(auto s : reci_novo)
        cout << s << ": " << (nadji(drvo, s, 0) ? "da" : "ne") << endl;
        
    return 0;
}

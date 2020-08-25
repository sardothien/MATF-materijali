/* Konstruisati algoritam koji za datih n reci
 * pronalazi najduzi zajednicki prefiks. */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    bool krajKljuca = false;
    unordered_map<char, cvor*> grane;
};

void umetni(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        drvo->krajKljuca = true;
        return;
    }
    
    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        drvo->grane[w[i]] = new cvor();
    
    umetni(drvo->grane[w[i]], w, i+1);
}

void najduziZajednickiPrefiks(cvor* drvo, string &nzp){
    /* Spustamo se niz stablo sve dok ne dodjemo do prvog lista 
     * ili dok god cvor ima samo jednog potomka, to nam je znak
     * da sve reci imaju isti prefiks. */
    while(drvo && !drvo->krajKljuca && drvo->grane.size() == 1){
        auto it = drvo->grane.begin();
        nzp += it->first; // char
        drvo = it->second; // cvor*
    }
}

int main(){
    
    vector<string> reci = {
        "code", "codecs", "coder", "coding"
    };
    
    cvor* drvo = new cvor();
    
    for(auto s : reci)
        umetni(drvo, s, 0);
    
    string nzp = "";
    najduziZajednickiPrefiks(drvo, nzp);
    
    cout << nzp << endl;
    
    return 0;
}

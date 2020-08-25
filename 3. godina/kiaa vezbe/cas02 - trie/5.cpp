/* Koristeci prefiskna stabla, pronaci i ispisati k reci
 * koje se javljaju najveci broj puta u datom skupu reci S. */

#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct cvor {
    string rec = "";
    int br = 0;
    unordered_map<char, cvor*> grane;
};

void umetni(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        drvo->rec = w;
        drvo->br++;
        return;
    }
    
    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        drvo->grane[w[i]] = new cvor();
    
    umetni(drvo->grane[w[i]], w, i+1);
}

void smestiUHip(cvor* drvo, auto& hip){
    if(drvo->rec != "")
        hip.push(drvo);
    
    auto pocetak = drvo->grane.begin();
    auto kraj = drvo->grane.end();
    
    while(pocetak != kraj){
        smestiUHip(pocetak->second, hip);
        pocetak++;
    }
}

struct poredi {
    bool operator()(cvor* n1, cvor* n2){
        return n1->br < n2->br;
    }
};

int main(){
    
    vector<string> reci = {
        "code", "coder", "coding", "codable", "codec", "codecs", "coded",
		"codeless", "codec", "codecs", "codependence", "codex", "codify",
		"codependents", "codes", "code", "coder", "codesign", "codec",
		"codeveloper", "codrive", "codec", "codecs", "codiscovered"
    };
    
    cvor* drvo = new cvor();
    
    for(auto s : reci)
        umetni(drvo, s, 0);
    
    priority_queue<cvor*, vector<cvor*>, poredi> hip;
    smestiUHip(drvo, hip);
    
    int k = 3;
    
    cvor* tmp;
    while(k && hip.size()){
        tmp = hip.top();
        hip.pop();
        cout << tmp->rec << " : " << tmp->br << endl;
        k--;
    }
    
    return 0;
}

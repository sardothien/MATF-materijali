/* U datom skupu reci S pronaci rec koja se javlja najveci 
 * broj puta. Za resenje zadatka koristiti prefiksna stabla. */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    string rec = "";
    int brPojavljivanja = 0;
    unordered_map<char, cvor*> grane;
};

void umetni(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        drvo->rec = w;
        drvo->brPojavljivanja++;
        return;
    }
    
    auto it = drvo->grane.find(w[i]);
    if(it == drvo->grane.end())
        drvo->grane[w[i]] = new cvor();
    
    umetni(drvo->grane[w[i]], w, i+1);
}

void najvisePojavljivanja(cvor* drvo, string& maxRec, int& maxBr){
    if(drvo->rec != ""){
        if(drvo->brPojavljivanja > maxBr){
            maxBr = drvo->brPojavljivanja;
            maxRec = drvo->rec;
        }
    }
    
    auto pocetak = drvo->grane.begin();
    auto kraj = drvo->grane.end();
    
    while(pocetak != kraj){
        najvisePojavljivanja(pocetak->second, maxRec, maxBr);
        pocetak++;
    }
}

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
    
    string maxRec = "";
    int maxBr = 0;
    
    najvisePojavljivanja(drvo, maxRec, maxBr);
    
    cout << maxRec << endl;
    
    return 0;
}

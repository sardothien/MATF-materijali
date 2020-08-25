/* Neka je dat skup reci D i neka niska s (bez belina). Proveriti 
 * da li se pomocu reci iz skupa D moze formirati niska s. */

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

bool mozeSeFormirati(cvor* drvo, string& s){
    int n = s.size();
    
    vector<bool> uDrvetu(n);
    uDrvetu[0] = true;
    
    cvor* tmp;
    
    for(int i = 0; i < n; i++){
        if(uDrvetu[i]){
            tmp = drvo;
            for(int j = i; j < n; j++){
                auto it = tmp->grane.find(s[j]);
                if(it == tmp->grane.end())
                    break;
                else
                    tmp = tmp->grane[s[j]];
                
                if(tmp->krajKljuca)
                    uDrvetu[j+1] = true;
                
                if(j == n-1)
                    return true;
            }
        }
    }
    
    return false;
}

int main(){
    
    vector<string> reci = {
        "this", "th", "is", "famous", "word", "break", "b", "r",
        "e", "a", "k", "br", "bre", "brea", "ak", "prob", "lem"
    };
    
    string s = "wordbreakproblem";
    
    cvor* drvo = new cvor();
    
    for(auto w : reci)
        umetni(drvo, w, 0);
    
    if(mozeSeFormirati(drvo, s))
        cout << "Moze!" << endl;
    else
        cout << "Ne moze!" << endl; 
    
    return 0;
}

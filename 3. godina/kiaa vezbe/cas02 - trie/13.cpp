/* Napisi program koji omogucava unos genetskih sekvenci i koji za 
 * svaku unetu sekvencu ispisuje koliko ima sekvenci kojima je
 * sekvenca koja se unosi prefiks. */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    cvor() {
        br = 0;
        grane[0] = grane[1] = grane[2] = grane[3] = nullptr;
    }
    
    int br;
    // imamo 4 grane: (c, t, g, a)
    cvor* grane[4];
};

int kod(char c){
    switch(c){
        case 'c': return 0;
        case 't': return 1;
        case 'g': return 2;
        case 'a': return 3;
        default: return -1;
    }
}

int brojPrefiksa(cvor* drvo, const string& niska){
    cvor* tmp = drvo;
    
    for(char c : niska){
        if(tmp->grane[kod(c)] == nullptr)
            return 0;
        
        tmp = tmp->grane[kod(c)];
    }
    
    if(tmp == nullptr)
        return 0;
    
    return tmp->br;
}

void umetni(cvor* drvo, const string& niska){
    cvor* tmp = drvo;
    
    for(char c : niska){
        if(tmp->grane[kod(c)] == nullptr)
            tmp->grane[kod(c)] = new cvor();
        
        tmp = tmp->grane[kod(c)];
        tmp->br++;
    }
}

int main(){
    
    cvor* drvo = new cvor();
    
    string niska;
    
    while(cin >> niska){
        cout << brojPrefiksa(drvo, niska) << endl;
        umetni(drvo, niska);
    }
    
    return 0;
}

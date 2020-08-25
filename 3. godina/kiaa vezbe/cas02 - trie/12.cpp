/* Niz telefonskih brojeva je korektan ako nijedan broj nije 
 * prefiks drugog. Napisi program koji odredjuje da li je niz 
 * unetih brojeva korektan. */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct cvor {
    unordered_map<char, cvor*> grane;
};

cvor* napravi(const string& broj, int i){
    if(i == broj.size())
        return nullptr;
    
    cvor* c = new cvor();
    c->grane[broj[i]] = napravi(broj, i+1);
    
    return c;
}

bool ubaci(cvor* drvo, const string& broj, int i){
    if(i == broj.size() || drvo == nullptr)
        return false;
    
    auto it = drvo->grane.find(broj[i]);
    if(it == drvo->grane.end()){
        drvo->grane[broj[i]] = napravi(broj, i+1);
        return true;
    }
    else
        return ubaci(it->second, broj, i+1);
}

int main(){
    
    // broj brojeva
    int n;
    cin >> n;
    
    bool okay = true;
    
    string broj;
    cin >> broj;
    
    cvor* drvo = napravi(broj, 0);
    
    for(int i = 0; i < n-1; i++){
        cin >> broj;
        
        if(okay && !ubaci(drvo, broj, 0))
            okay = false;
    }
    
    if(okay)
        cout << "da" << endl;
    else
        cout << "ne" << endl;
    
    return 0;
}

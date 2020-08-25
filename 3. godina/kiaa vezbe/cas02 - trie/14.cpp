/* Napisi program koji odredjuje koliko razlicitih podniski 
 * ima data niska. */

#include<iostream>
using namespace std;

struct cvor {
    cvor(){
        grane[0] = grane[1] = grane[2] = grane[3] = nullptr;
    }
    
    // koristimo samo slova (a, b, c, d)
    cvor* grane[4];
};

void umetni(cvor* drvo, const string& w, int i){
    cvor* tmp = drvo;
    
    while(i < w.length()){
        if(tmp->grane[w[i]-'a'] == nullptr)
            tmp->grane[w[i]-'a'] = new cvor();
        
        tmp = tmp->grane[w[i]-'a'];
        i++;
    }
}

int brojCvorova(cvor* drvo){
    if(drvo == nullptr)
        return 0;
    
    int broj = 1;
    for(int i = 0; i < 4; i++)
        broj += brojCvorova(drvo->grane[i]);
    
    return broj;
}

int main(){
    
    string niska;
    cin >> niska;
    
    cvor* drvo = new cvor();
    
    for(int i = 0; i < niska.length(); i++)
        umetni(drvo, niska, i);
    
    cout << brojCvorova(drvo) << endl;
    
    return 0;
}

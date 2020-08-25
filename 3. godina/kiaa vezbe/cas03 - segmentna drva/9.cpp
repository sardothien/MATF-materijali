/* Konstruisati algoritam za izracunavanje maksimalnog 
 * proizvoda dva broja niza A u intervalu [a, b]. */

#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

struct cvor{
    int najveci;
    int drugi_najveci;
};

void formiraj(const vector<int>& niz, vector<cvor>& drvo, int k, int x, int y){
    if(x == y){
        drvo[k].najveci = niz[x];
        drvo[k].drugi_najveci = INT_MIN;
    }
    else{
        int sr = (x+y) / 2;
        
        formiraj(niz, drvo, 2*k, x, sr);
        formiraj(niz, drvo, 2*k+1, sr+1, y);
        
        drvo[k].najveci = max(drvo[2*k].najveci, drvo[2*k+1].najveci);
        drvo[k].drugi_najveci = min(max(drvo[2*k].najveci, drvo[2*k+1].drugi_najveci),
                                    max(drvo[2*k].drugi_najveci, drvo[2*k+1].najveci));
    }
}

cvor najveciCinioci(const vector<cvor>& drvo, int k, int x, int y, int a, int b){
    
    cvor rez;
    rez.najveci = INT_MIN;
    rez.drugi_najveci = INT_MIN;    
    
    if(b < x || a > y)
        return rez;
    
    if(a <= x && b >= y)
        return drvo[k];
    
    int sr = (x+y) / 2;
    
    cvor levo = najveciCinioci(drvo, 2*k, x, sr, a, b);
    cvor desno = najveciCinioci(drvo, 2*k+1, sr+1, y, a, b);
    
    rez.najveci = max(levo.najveci, desno.najveci);
    rez.drugi_najveci = min(max(levo.najveci, desno.drugi_najveci), 
                            max(levo.drugi_najveci, desno.najveci));
    
    return rez;
}

int main(){
    
    vector<int> niz = {
        1, 5, 3, 8, 5, 4, 7
    };
    
    int n = niz.size();
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<cvor> drvo(velicina);
  
    formiraj(niz, drvo, 1, 0, n-1);
    
    int a, b;
    cin >> a >> b;
    
    cvor rez = najveciCinioci(drvo, 1, 0, n-1, a, b);
    
    cout << (rez.najveci * rez.drugi_najveci) << endl;
    
    return 0;
}

/* Konstruisati algoritam za odredjivanje broja parnih 
 * brojeva niza A. */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void formiraj(const vector<int>& niz, vector<int>& drvo, int k, int x, int y){
    if(x == y){
        if(niz[x] % 2 == 0)
            drvo[k] = 1;
        else
            drvo[k] = 0;
    }
    else{
        int sr = (x+y) / 2;
        
        formiraj(niz, drvo, 2*k, x, sr);
        formiraj(niz, drvo, 2*k+1, sr+1, y);
        
        drvo[k] = drvo[2*k] + drvo[2*k+1];
    }
}

int main(){
    
    vector<int> niz = {
        5, 8, 6, 3, 2, 7, 2, 6
    };
    
    int n = niz.size();
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<int> drvo(velicina);
    
    formiraj(niz, drvo, 1, 0, n-1);
    
    cout << drvo[1] << endl;
    
    
    return 0;
}

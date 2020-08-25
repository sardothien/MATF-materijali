/* Konstruisati algoritam za odredjivanje broja slozenih brojeva 
 * niza A u intervalu [a, b]. (svodi se na sabiranje) */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define MAX (1000)

void eratosten(vector<bool>& prost){
    prost[1] = true;
    
    for(int d = 2; d*d <= MAX; d++)
        if(prost[d])
            for(int i = 2*d; i <= MAX; i += d)
                prost[i] = false;
}

void formiraj(const vector<int>& niz, vector<int>& drvo, const vector<bool>& prost, int k, int x, int y){
    if(x == y)
        drvo[k] = prost[niz[x]] ? 0 : 1;
    else{
        int sr = (x+y) / 2;
        
        formiraj(niz, drvo, prost, 2*k, x, sr);
        formiraj(niz, drvo, prost, 2*k+1, sr+1, y);
        
        drvo[k] = drvo[2*k] + drvo[2*k+1];
    }
}

int brojSlozenih(const vector<int>& drvo, int k, int x, int y, int a, int b){
    if(b < x || a > y)
        return 0;
    
    if(a <= x && b >= y)
        return drvo[k];
    
    int sr = (x+y) / 2;
    
    return brojSlozenih(drvo, 2*k, x, sr, a, b) 
         + brojSlozenih(drvo, 2*k+1, sr+1, y, a, b);
}

int main(){
    
    vector<int> niz = {
        5, 8, 6, 3, 2, 7, 2, 6
    };
    
    int n = niz.size();
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<int> drvo(velicina);
    
    vector<bool> prost(MAX);
    fill(prost.begin(), prost.end(), true);
    
    eratosten(prost);
    
    formiraj(niz, drvo, prost, 1, 0, n-1);
    
    int a, b;
    cin >> a >> b;
    
    cout << brojSlozenih(drvo, 1, 0, n-1, a, b) << endl;
    
    return 0;
}

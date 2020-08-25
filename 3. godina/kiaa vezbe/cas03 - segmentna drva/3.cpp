/* Napisati rekurzivnu i iterativnu funkciju za azuriranje
 * vrednosti u segmentnom stablu. */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void formiraj(const vector<int>& niz, vector<int>& drvo, int k, int x, int y){
    if(x == y)
        drvo[k] = niz[x];
    else{
        int sr = (x+y) / 2;
        
        formiraj(niz, drvo, 2*k, x, sr);
        formiraj(niz, drvo, 2*k+1, sr+1, y);
        
        drvo[k] = drvo[2*k] + drvo[2*k+1];
    }
}

void izmeniIterativno(vector<int>& drvo, int n, int i, int vr){
    int k = i+n;
    
    drvo[k] = vr;
    
    for(k /= 2; k >= 1; k /= 2)
        drvo[k] = drvo[2*k] + drvo[2*k+1];
}

void izmeniRekurzivno(vector<int>& drvo, int k, int x, int y, int i, int vr){
    if(x == y)
        drvo[k] = vr;
    else{
        int sr = (x+y) / 2;
        
        if(x <= i && i <= sr)
            izmeniRekurzivno(drvo, 2*k, x, sr, i, vr);
        else
            izmeniRekurzivno(drvo, 2*k+1, sr+1, y, i, vr);
        
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
    
    for(int x : drvo)
        cout << x << " ";
    cout << endl;
    
    izmeniIterativno(drvo, n, 2, 8);
    izmeniRekurzivno(drvo, 1, 0, n-1, 2, 8);
    
    for(int x : drvo)
        cout << x << " ";
    cout << endl;
    
    return 0;
}

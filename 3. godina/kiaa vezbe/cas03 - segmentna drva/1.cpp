/* Napisati rekurzivnu i iterativnu funkciju za kreiranje 
 * segmentnog stabla od datog niza. */

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

void formirajIterativno(const vector<int>& niz, int n, vector<int>& drvo){
    copy_n(niz.begin(), n, drvo.begin()+n);
    
    for(int k = n-1; k >= 1; k--)
        drvo[k] = drvo[2*k] + drvo[2*k+1];
}

void formirajRekurzivno(const vector<int>& niz, vector<int>& drvo, int k, int x, int y){
    if(x == y)
        drvo[k] = niz[x];
    else{
        int sr = (x+y) / 2;
        
        formirajRekurzivno(niz, drvo, 2*k, x, sr);
        formirajRekurzivno(niz, drvo, 2*k+1, sr+1, y);
        
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
    
    formirajIterativno(niz, n, drvo);
    formirajRekurzivno(niz, drvo, 1, 0, n-1);
    
    for(int x : drvo)
        cout << x << " ";
    cout << endl;
    
    return 0;
}

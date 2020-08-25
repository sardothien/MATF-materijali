/* Konstruisati algoritam za odredjivanje broja parnih 
 * brojeva niza A u intervalu [a, b]. */

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
        
        return;
    }
    
    int sr = (x+y) / 2;
        
    formiraj(niz, drvo, 2*k, x, sr);
    formiraj(niz, drvo, 2*k+1, sr+1, y);
        
    drvo[k] = drvo[2*k] + drvo[2*k+1];
}

int suma(const vector<int>& drvo, int k, int x, int y, int a, int b){
    if(x > b || y < a)
        return 0;
    
    if(a <= x && b >= y)
        return drvo[k];
    
    int sr = (x+y) / 2;
    
    return suma(drvo, 2*k, x, sr, a, b)
         + suma(drvo, 2*k+1, sr+1, y, a, b);
}

int main(){
    
    vector<int> niz = {
        1, 2, 3, 4, 5, 6, 7, 8
    };
    
    int n = niz.size();
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<int> drvo(velicina);
    
    formiraj(niz, drvo, 1, 0, n-1);
    
    int a, b;
    cin >> a >> b;
    
    cout << suma(drvo, 1, 0, n-1, a, b) << endl;
        
    return 0;
}

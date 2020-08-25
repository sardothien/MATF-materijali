/* Napisati funkciju za racunanje sume kvadrata elemenata
 * niza A koji su intervalu [a, b]. Koristiti segmentna stabla. */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void formiraj(const vector<int>& niz, vector<int>& drvo, int k, int x, int y){
    if(x == y)
        drvo[k] = pow(niz[x], 2);
    else{
        int sr = (x+y) / 2;
        
        formiraj(niz, drvo, 2*k, x, sr);
        formiraj(niz, drvo, 2*k+1, sr+1, y);
        
        drvo[k] = drvo[2*k] + drvo[2*k+1];
    }
}

int suma(const vector<int>& drvo, int k, int x, int y, int a, int b){
    if(b < x || a > y)
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

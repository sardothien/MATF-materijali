/* Napisati rekurzivnu i iterativnu funkciju za racunanje sume 
 * elemenata niza A koji su intervalu [a, b]. Koristiti 
 * segmentna stabla. */

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

int sumaIterativno(const vector<int>& drvo, int n, int a, int b){
    a += n;
    b += n;
    
    int zbir = 0;
    
    while(a <= b){
        if(a % 2 == 1)
            zbir += drvo[a++];
        if(b % 2 == 0)
            zbir += drvo[b--];
        
        a /= 2;
        b /= 2;
    }
    
    return zbir;
}

int sumaRekurzivno(const vector<int>& drvo, int k, int x, int y, int a, int b){
    
    if(b < x || a > y)
        return 0;
    else if(a <= x && b >= y)
        return drvo[k];
    
    int sr = (x+y) / 2;
    
    return sumaRekurzivno(drvo, 2*k, x, sr, a, b) 
         + sumaRekurzivno(drvo, 2*k+1, sr+1, y, a, b);
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
    
    cout << sumaIterativno(drvo, n, 0, 2) << endl;
    cout << sumaRekurzivno(drvo, 1, 0, n-1, 0, 2) << endl;
    
    return 0;
}

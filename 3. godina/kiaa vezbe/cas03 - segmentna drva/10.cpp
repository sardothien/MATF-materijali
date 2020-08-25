/* Napisi program koji izracunava zbirove datih segmenata niza, 
 * pri cemu se tokom rada programa pojedini elementi niza mogu menjati. */
// O(logn)

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

int suma(const vector<int>& drvo, int k, int x, int y, int a, int b){
    if(b < x || a > y)
        return 0;
    
    if(a <= x && b >= y)
        return drvo[k];
    
    int sr = (x+y) / 2;
    
    return suma(drvo, 2*k, x, sr, a, b) 
         + suma(drvo, 2*k+1, sr+1, y, a, b);
}

void postavi(vector<int>& drvo, int k, int x, int y, int i, int vr){
    if(x == y)
        drvo[k] = vr;
    else{
        int sr = (x+y) / 2;
        
        if(x <= i && i <= sr)
            postavi(drvo, 2*k, x, sr, i, vr);
        else
            postavi(drvo, 2*k+1, sr+1, y, i, vr);
        
        drvo[k] = drvo[2*k] + drvo[2*k+1];
    }
}

int main(){
    
    // broj elemenata niza
    int n;
    cin >> n;
    
    vector<int> niz(n);
    for(int i = 0; i < n; i++)
        cin >> niz[i];
    
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<int> drvo(velicina);
    
    formiraj(niz, drvo, 1, 0, n-1);
    
    // broj upita
    int m;
    cin >> m;
    
    char oznaka;
    int a, b;
    
    for(int i = 0; i < m; i++){
        cin >> oznaka >> a >> b;
        if(oznaka == 'z'){
            cout << suma(drvo, 1, 0, n-1, a, b) << endl;
        }
        else if(oznaka == 'p'){
            postavi(drvo, 1, 0, n-1, a, b);
        }
    }    
    
    return 0;
}

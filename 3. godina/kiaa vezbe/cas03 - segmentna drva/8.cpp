/* Konstruisati algoritam za odredjivanje maksimalnog
 * elementa niza A u intervalu [a, b]. */

#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
using namespace std;

void formiraj(const vector<int>& niz, vector<int>& drvo, int k, int x, int y){
    if(x == y)
        drvo[k] = niz[x];
    else{
        int sr = (x+y) / 2;
        
        formiraj(niz, drvo, 2*k, x, sr);
        formiraj(niz, drvo, 2*k+1, sr+1, y);
        
        drvo[k] = max(drvo[2*k], drvo[2*k+1]);
    }
}

int maxElement(const vector<int>& drvo, int k, int x, int y, int a, int b){
    if(b < x || a > y)
        return INT_MIN;
    
    if(a <= x && b >= y)
        return drvo[k];
    
    int sr = (x+y) / 2;
    
    return max(maxElement(drvo, 2*k, x, sr, a, b), 
               maxElement(drvo, 2*k+1, sr+1, y, a, b));
}

int main(){
    
    vector<int> niz = {
        1, 5, 3, 8, 5, 4, 7, 2
    };
    
    int n = niz.size();
    int visina = ceil(log2(n));
    int velicina = 2*pow(2, visina);
    
    vector<int> drvo(velicina);
    
    formiraj(niz, drvo, 1, 0, n-1);
    
    int a, b;
    cin >> a >> b;
    
    cout << maxElement(drvo, 1, 0, n-1, a, b) << endl;
    
    return 0;
}

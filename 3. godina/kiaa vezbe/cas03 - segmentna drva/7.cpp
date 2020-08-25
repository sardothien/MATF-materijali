/* Inverizijom zovemo 2 elementa niza za koja vazi sledece:
 * i < j i a[i] > a[j]. Konstruisati algoritam za izracunavanje
 * broja inverzijau datom nizu A. */

#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int brojInverzija(const vector<int>& drvo, int k, int x, int y, int a, int b){
    if(b < x || a > y)
        return 0;
    
    if(a <= x && b >= y)
        return drvo[k];
    
    int sr = (x+y) / 2;
    
    return brojInverzija(drvo, 2*k, x, sr, a, b)
         + brojInverzija(drvo, 2*k+1, sr+1, y, a, b);
}

void dodajElement(vector<int>& drvo, int k, int x, int y, int i){
    if(x == y){
        drvo[k] = 1;
        return;
    }
    
    int sr = (x+y) / 2;
    
    if(i <= sr)
        dodajElement(drvo, 2*k, x, sr, i);
    else
        dodajElement(drvo, 2*k+1, sr+1, y, i);
    
    drvo[k] = drvo[2*k] + drvo[2*k+1];
}

int main(){
    
    vector<int> niz = {
        8, 4, 2, 1
    };
    
    int n = niz.size();
    
    int max = *max_element(niz.begin(), niz.end());
    int visina = ceil(log2(max));
    int velicina = 2*pow(2, visina);
    
    vector<int> drvo(velicina);
    fill(drvo.begin(), drvo.end(), 0);
    
    int rez = 0;
    
    for(int i = 0; i < n; i++){
        rez += brojInverzija(drvo, 1, 1, max, niz[i]+1, max);
        dodajElement(drvo, 1, 1, max, niz[i]);
    }
    
    cout << rez << endl;
    
    return 0;
}

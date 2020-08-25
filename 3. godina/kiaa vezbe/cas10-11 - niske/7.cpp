/* Data je niska s duzine n, koja se sastoji samo iz malih
 * slova engleskog alfabeta. Izracunati broj razlicitih 
 * segmenata ove niske algoritmom slozenosti O(n^2logn). */

#include<iostream>
#include<vector>
#include<set>
using namespace std;

int brojRazlicitihSegmenata(string& rec){
    
    int n = rec.size();
    int p = 31;
    int m = 1e9+9;
    
    vector<long long> pStepen(n);
    pStepen[0] = 1;
    
    for(int i = 1; i < n; i++)
        pStepen[i] = (pStepen[i-1]*p) % m;
    
    vector<long long> hes(n+1, 0);
    
    for(int i = 0; i < n; i++)
        hes[i+1] = (hes[i] + (rec[i]-'a'+1)*pStepen[i]) % m;
    
    int br = 0;
    for(int l = 1; l <= n; l++){
        set<long long> hes_duzine_l;
        for(int i = 0; i <= n-1; i++){
            long long h = (hes[i+1] + m - hes[i]) % m;
            h = (h * pStepen[n-i-1]) % m;
            hes_duzine_l.insert(h);
        }
        br += hes_duzine_l.size();
    }
    
    return br;
}

int main(){
    
    string rec;
    cin >> rec;
    
    cout << brojRazlicitihSegmenata(rec) << endl;
    
    return 0;
}

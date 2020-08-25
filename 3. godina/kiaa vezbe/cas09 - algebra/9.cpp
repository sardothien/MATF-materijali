/* Data su dva niza brojeva r: r0, r1,..., r_n-1 i
 * m: m0, m1,..., m_n-1 pri cemu za svaki par brojeva
 * niza m vazi da su uzajamno prosti. Odrediti najmanji
 * pozitivan broj x za koji vazi Kineska Teorema o ostacima. */

#include<iostream>
#include<vector>
using namespace std;

bool mod_inverz(long long a, long long m, long long& x){
    long long r = m, r1 = a;
    x = 0;
    long long x1 = 1;
    
    while(r1 > 0){
        long long q = r/r1;
        long long pom;
        
        pom = r;
        r = r1;
        r1 = pom - q*r1;
        
        pom = x;
        x = x1;
        x1 = pom - q*x1;
    }
    
    if(x < 0)
        x += m;
    
    return r == 1;
}

long long pm(long long x, long long y, long long m){
    return ((x%m) * (y%m)) % m;
}

long long pm(long long x, long long y, long long z, long long m){
    return pm(pm(x, y, m), z, m);
}

long long zm(long long x, long long y, long long m){
    return ((x%m) + (y%m)) % m;
}

bool kto(long long m[], long long r[], int n, long long& rez){
    
    long long M = 1;
    
    for(int i = 0; i < n; i++)
        M *= m[i];
    
    rez = 0;
    for(int i = 0; i < n; i++){
        long long zi = M / m[i];
        long long zi_inv;
        
        if(!mod_inverz(zi, m[i], zi_inv))
            return false;
        
        rez = zm(rez, pm(r[i], zi_inv, M), M);
    }
    
    return true;
}

int main(){
    
    long long r[3], m[3];
    
    for(int i = 0; i < 3; i++)
        cin >> r[i] >> m[i];
    
    long long rez;
    kto(m, r, 3, rez);
    
    cout << rez << endl;    
    
    return 0;
}

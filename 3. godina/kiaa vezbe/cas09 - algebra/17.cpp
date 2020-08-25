/* Odrediti n-ti Fibonacijev broj. */
// O(log(n))

#include<iostream>
#include<vector>
using namespace std;

#define MOD 10000

vector<int> mat_mul(vector<int> m1, vector<int> m2){
    vector<int> m(4);

    // mod zbog velikih brojeva do kojih se brzo dolazi
    m[0] = (m1[0] * m2[0] + m1[1] * m2[2]) % MOD;
    m[1] = (m1[0] * m2[1] + m1[1] * m2[3]) % MOD;
    m[2] = (m1[2] * m2[0] + m1[3] * m2[2]) % MOD;
    m[3] = (m1[2] * m2[1] + m1[3] * m2[3]) % MOD;

    return m;
}

vector<int> fastpow(vector<int> a, int n){
    vector<int> rez = {1, 0, 0, 1};
    
    while(n > 0){
        if(n & 1)
            rez = mat_mul(rez, a);
        
        a = mat_mul(a, a);
        n >>= 1;
    }
    
    return rez;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<int> a = {1, 1, 1, 0};
    
    vector<int> a_n = fastpow(a, n);
    cout << a_n[2] << endl;
    
    return 0;
}

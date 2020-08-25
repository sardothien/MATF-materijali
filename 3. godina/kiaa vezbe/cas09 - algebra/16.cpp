/* Algoritam brzog stepenovanja: 
 * dati su brojevi a i n i treba izracunati
 * koliko je a^n. */
// O(log(n))

#include<iostream>
using namespace std;

int fastpow(int a, int n){
    int rez = 1;
    
    while(n > 0){
        if(n & 1)
            rez *= a;
        a *= a;
        n >>= 1;
    }
    
    return rez;
}

int main(){
    
    int a, n;
    cin >> a >> n;
    
    cout << fastpow(a, n) << endl;
    
    return 0;
}

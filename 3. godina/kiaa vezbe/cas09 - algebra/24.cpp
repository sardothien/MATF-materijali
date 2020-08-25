/* Број је савршен ако је једнак суми својих делилаца (у збир делилаца броја
 * се убраја број 1, али не и сам тај број). Написати програм који одређује
 * најмањи савршен број у интервалу [n − k, n + k]. */

#include<iostream>
using namespace std;

int zbirDelilaca(int n){
    int n0 = n;
    int zbir = 1;
    int p = 2;
    
    while(p*p <= n){
        int zbir_pi = 1;

        while(n % p == 0){
            zbir_pi = zbir_pi * p + 1;
            n /= p;
        }
        
        zbir *= zbir_pi;
        p++;
    }
    
    if(n > 1)
        zbir *= (1 + n);
    
    return zbir - n0;
}

bool savrsen(int n){
    return zbirDelilaca(n) == n;
}

int main(){
    
    int n, k;
    cin >> n >> k;
    
    bool postojiSavrsen = false;
    int savrsenBroj;
    
    for(int i = n-k; i <= n+k; i++){
        if(savrsen(i)){
            savrsenBroj = i;
            postojiSavrsen = true;
            break;
        }
    }
    
    if(postojiSavrsen)
        cout << savrsenBroj << endl;
    else
        cout << "NE" << endl;
    
    return 0;
}

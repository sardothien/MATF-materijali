/* Za dati prirodan broj n izracunati vrednost Ojlerove
 * funkcije - broj prirodnih brojeva manjih ili jednakih
 * n koji su uzajamno prosti sa n. */
// O(sqrt(n))

#include<iostream>
using namespace std;

int ojler(int n){
    int br = n;
    
    for(int p = 2; p*p <= n; p++){
        if(n % p == 0){
            while(n % p == 0)
                n /= p;
            br -= br/p;
        }
    }
    
    if(n > 1)
        br -= br/n;
    
    return br;
}

int main(){
    
    int n;
    cin >> n;
    
    cout << ojler(n) << endl;
    
    return 0;
}

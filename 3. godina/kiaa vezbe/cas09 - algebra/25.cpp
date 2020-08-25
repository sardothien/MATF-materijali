/* Бројеви су пријатељски, ако је збир делилаца првог броја једнак
 * другом, а збир делилаца другог броја једнак првом броју (у збир
 * делилаца броја се убраја број 1, али не и сам тај број). Напиши 
 * програм који исписује све парове пријатељских бројева такве да
 * оба броја леже у датом интервалу. */

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

void prijateljskiBrojevi(int a, int b){
    
    for(int i = a; i <= b; i++){
        int j = zbirDelilaca(i);
        if(a <= j && j <= b && i <= j && zbirDelilaca(j) == i)
            cout << i << " " << j << endl;
    }
}

int main(){
    
    int a, b;
    cin >> a >> b;
    
    prijateljskiBrojevi(a, b);
    
    return 0;
}

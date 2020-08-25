/* Za data dva cela broja a i m odrediti multiplikativni
 * inverz broja a po modulu m. */

#include<iostream>
using namespace std;

int prosireniNZD(int a, int m, int& x, int& y){
    if(m == 0){
        x = 1;
        y = 0;
        return a;
    }
    
    int x1, y1;
    
    int nzd = prosireniNZD(m, a % m, x1, y1);
    x = y1;
    y = x1 - (a/m)*y1;
    
    return nzd;
}

int modInverz(int a, int m){
    int x, y;
    int d = prosireniNZD(a, m, x, y);
    
    if(d != 1){
        cout << "Ne postoji inverz" << endl;
        return -1;
    }
    else{
        int inverz = (x % m + m) % m;
        return inverz;
    }
}

int main(){
    
    int a, m;
    cin >> a >> m;
    
    cout << modInverz(a, m) << endl;
    
    return 0;
}

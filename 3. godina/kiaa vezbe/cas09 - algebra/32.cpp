/* Дата су два полинома, P и Q степенима и низовима својих 
 * коефицијената. Oдредити њихов збир и производ. */

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

const int MAX_STEPEN = 20;

struct Polinom {
    double a[2 * MAX_STEPEN + 1];
    int n;
};

void unos(Polinom& P){
    cin >> P.n;
    for(int i = P.n; i >= 0; i--)
        cin >> P.a[i];
}

void prikaz(Polinom P){
    for(int i = P.n; i >= 0; i--)
        cout << fixed << setprecision(2) << showpoint << P.a[i] << " ";
    cout << endl;
}

Polinom zbir(Polinom P, Polinom Q){
    Polinom R;
    R.n = max(P.n, Q.n);
    
    for(int i = 0; i < R.n; i++)
        R.a[i]=0;
    
    for(int i = 0; i <= R.n; i++){
        if(i <= P.n)
            R.a[i] += P.a[i];
        if(i <= Q.n)
            R.a[i] += Q.a[i];
    }
    
    return R;
}

Polinom proizvod(Polinom P, Polinom Q){
    Polinom R;
    R.n = P.n + Q.n;
    
    for(int i = 0; i <= R.n; i++)
        R.a[i]=0;
    
    for(int i = 0; i <= P.n; i++)
        for(int j = 0; j <= Q.n; j++)
            R.a[i + j] += P.a[i] * Q.a[j];
    
    return R;
}

int main(){
    
    Polinom P, Q, R;
    
    unos(P);
    unos(Q);
    
    R = zbir(P, Q);
    prikaz(R);
    
    R = proizvod(P, Q);
    prikaz(R);
    
    return 0;
}

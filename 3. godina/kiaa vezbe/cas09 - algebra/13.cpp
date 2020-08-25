/* Programer Ika je ljubitelj paralelizacije. Pokusava da
 * paralelizuje svoj program koji radi nad x podataka tako
 * da svaki procesor obradjuje isti broj podataka. Ako 
 * rasporedi podatke na n1 procesora, ostaje mu a1 podataka
 * viska, ako rasporedi podatke na n2 procesora, ostaje mu a2
 * podataka viska, a ako ih rasporedi na n3 procesora, ostaje
 * mu a3 podataka viska. Ako se znaju brojevi n1, n2, n3, a1, 
 * a2, a3 i ako se zna da su brojevi ni uzajamno prosti, napisi
 * program koji odredjuje x. */

#include<iostream>
using namespace std;

bool modInverz(long long a, long long n, long long& x){
    long long r = n, r1 = a;
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
        x += n;
    
    return r == 1;
}

long long pm(long long x, long long y, long long n){
    return ((x%n) * (y%n)) % n;
}

long long pm(long long x, long long y, long long z, long long n){
    return pm(pm(x, y, n), z, n);
}

long long zm(long long x, long long y, long long n){
    return ((x%n) + (y%n)) % n;
}

bool kto(long long n[], long long a[], int duzina, long long& rez){
    
    long long N = 1;
    for(int i = 0; i < duzina; i++)
        N *= n[i];
    
    rez = 0;
    
    for(int i = 0; i < duzina; i++){
        long long zi = N / n[i];
        long long zi_inv;
        
        if(!modInverz(zi, n[i], zi_inv))
            return false;
        
        rez = zm(rez, pm(a[i], zi_inv, zi, N), N);
    }
    
    return true;
}

int main(){
    
    long long n[3];
    long long a[3];
    
    for(int i = 0; i < 3; i++)
        cin >> n[i];
    
    for(int i = 0; i < 3; i++)
        cin >> a[i];
    
    long long rez;
    kto(n, a, 3, rez);
    
    cout << rez << endl;
    
    return 0;
}

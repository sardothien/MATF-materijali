/* Mile i Tanja moraju da razmene tajne poruke koje se sastoje
 * od puno velikih brojeva. Mile je zeleo da se dodatno zastiti
 * i da te brojeve pre slanja izmeni tako sto je svaki broj
 * pomnozio tajnim brojem a i izracunao ostatak pri deljenju
 * sa tajnim brojem n. Mile zna da ce Tanja lako desifrovati 
 * poruku ako zna brojeve a i n i ako su oni uzajamno prosti i
 * zato ih je izabrao bas na taj nacin. Napisati program koji
 * desifruje brojeve koje je Mile poslao.
 */

#include<iostream>
using namespace std;

bool modInverz(int a, int n, long long& x){
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

int main(){
    
    int a, n;
    cin >> a >> n;
    
    long long inv_a;
    modInverz(a, n, inv_a);
    
    long long x;
    while(cin >> x)
        cout << (inv_a*x) % n << endl;
    
    return 0;
}

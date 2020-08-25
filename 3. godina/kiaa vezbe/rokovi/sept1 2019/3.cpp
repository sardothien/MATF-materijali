/* Na takmičenju iz programiranja je ukupno n učesnika. Oni su podeljeni
 * u m timova tako da je u svakom timu najmanje 1 takmičar. Nakon 
 * takmičenja su se učesnici iz istih timova sprijateljili. Konstruisati
 * algoritam složenosti O(1) koji odredjuje maksimalan i minimalan broj 
 * novonastalih prijateljstava. Sa standardnog ulaza se unose brojevi 
 * n i m redom. U jednoj liniji standardnog izlaza ispisati 2 broja,
 * minimalan i maksimalan broj prijateljstava redom. NAPOMENA: Zbog 
 * potencijalno jako velikih brojeva u zadatku koristiti promenljive 
 * tipa long long. */

#include<iostream>
using namespace std;

int main(){
    
    long long n, m;
    cin >> n >> m;
    
    long long x = n - m;
    long long max = x*(x+1) / 2;

    long long sigurno = n / m - 1;
    long long pom = sigurno * (sigurno+1) / 2;
    long long min = pom*m;
    
    pom = n % m;
    
    if(pom){
        long long tmp = n / m;
        min += pom * tmp;
    }
    
    cout << min << " " << max << endl;
    
    return 0;
}

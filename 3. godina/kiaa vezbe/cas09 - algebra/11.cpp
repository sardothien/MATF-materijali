/* Mravi, pcele i komarci organizuju sportski turnir i zele da se
 * podele u timove tako da se svaki tim sastoji samo od 1 vrste
 * insekta, da svi timovi imaju isti broj clanova i da je svaki
 * insekt ukljucen tacno u 1 tim. Ako se zna broj insekata svake
 * od tri vrste, napisati program koji odredjuje najvecu mogucu
 * velicinu timova. */

#include<iostream>
using namespace std;

int nzd(int a, int b){
    if(b == 0)
        return a;
    
    return nzd(b, a%b);
}

int main(){
    
    int m, p, k;
    cin >> m >> p >> k;
    
    cout << nzd(nzd(m, p), k) << endl;
    
    return 0;
}

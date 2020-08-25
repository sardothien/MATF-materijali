/* Mali Vasa je dobio zadatak da izreze list papira dimenzije axb
 * na kvadrate max povrsine. Vasa najpre isece najveci moguci
 * kvadrat tako sto sece list papira po najduzoj stranici. Potom,
 * Vasa skloni kvadrat i nad preostalim pravougaonikom ponovi
 * isecanje kvadrata najvece povrsine. Nastavlja istu operaciju
 * sve dok preostali pravougaonik ne postane kvadrat. Konstruisati
 * algoritam slozenosti O(log(a+b)) koji za date vrednosti a i b
 * izracunava broj kvadrata koji se dobiju nakon isecanja. */

#include<iostream>
using namespace std;

int main(){

    int a, b;
    cin >> a >> b;

    if(a == b){
        cout << 1 << endl;
        return 0;
    }
    else if(a < b)
        swap(a, b);

    int br = 0;

    while(b != 0){
        br += a/b;
        int ostalo = a % b;
        a = b;
        b = ostalo;
    }

    cout << br << endl;

    return 0;
}

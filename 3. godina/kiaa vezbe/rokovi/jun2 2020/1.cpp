/* Dat je niz celih brojeva duzine n i broj x. Zadaje se
 * q upita oblika k v a b. Za svaki upit potrebno je na
 * poziciju k niza upisati broj v i zatim izracunati i
 * ispisati sumu elemenata i broj elemenata iz podsegmenta
 * niza [a, b] koji su veci od x. Napisati program koji
 * obradjuje zadate upite. Vremenska slozenost treba da
 * bude O(n+qlogn), a prostorna O(n). Sa standardnog ulaza
 * se ucitavaju brojevi n, q i x. Nakon toga se ucitava n
 * brojeva koji predstavljaju elemente niza. Konacno, ucitava
 * se q upita predstavljenih brojevima k, v, a i b. Zagarantovano
 * je da je zbir svih elemenata na bilo kom segmentu niza manji
 * od 2^31. Na standardni izlaz za svaki upit ispisati po dva
 * broja koji redom predstavljaju sumu i broj trazenih elemenata. */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void formiraj1(vector<int>& drvo, const vector<int>& niz, int k, int x, int y, int br){
    if(x == y){
        drvo[k] = niz[x] > br ? niz[x] : 0;
        return;
    }

    int sr = (x + y) / 2;

    formiraj1(drvo, niz, 2*k, x, sr, br);
    formiraj1(drvo, niz, 2*k+1, sr+1, y, br);

    drvo[k] = drvo[2*k] + drvo[2*k+1];
}

void formiraj2(vector<int>& drvo, const vector<int>& niz, int k, int x, int y, int br){
    if(x == y){
        drvo[k] = niz[x] > br ? 1 : 0;
        return;
    }

    int sr = (x + y) / 2;

    formiraj2(drvo, niz, 2*k, x, sr, br);
    formiraj2(drvo, niz, 2*k+1, sr+1, y, br);

    drvo[k] = drvo[2*k] + drvo[2*k+1];
}

void izmeni1(vector<int>& drvo, int k, int x, int y, int i, int vr, int br){
    if(x == y){
        drvo[k] = vr > br ? vr : 0;
        return;
    }

    int sr = (x+y) / 2;

    if(i <= sr)
        izmeni1(drvo, 2*k, x, sr, i, vr, br);
    else
        izmeni1(drvo, 2*k+1, sr+1, y, i, vr, br);

    drvo[k] = drvo[2*k] + drvo[2*k+1];
}

void izmeni2(vector<int>& drvo, int k, int x, int y, int i, int vr, int br){
    if(x == y){
        drvo[k] = vr > br ? 1 : 0;
        return;
    }

    int sr = (x+y) / 2;

    if(i <= sr)
        izmeni2(drvo, 2*k, x, sr, i, vr, br);
    else
        izmeni2(drvo, 2*k+1, sr+1, y, i, vr, br);

    drvo[k] = drvo[2*k] + drvo[2*k+1];
}

int suma1(vector<int>& drvo, int k, int x, int y, int a, int b){
    if(b < x || a > y)
        return 0;

    else if(a <= x && b >= y)
        return drvo[k];

    int sr = (x+y) / 2;

    return suma1(drvo, 2*k, x, sr, a, b) + suma1(drvo, 2*k+1, sr+1, y, a, b);
}

int suma2(vector<int>& drvo, int k, int x, int y, int a, int b){
    if(b < x || a > y)
        return 0;

    else if(a <= x && b >= y)
        return drvo[k];

    int sr = (x+y) / 2;

    return suma2(drvo, 2*k, x, sr, a, b) + suma2(drvo, 2*k+1, sr+1, y, a, b);
}

int main(){

    int n, q, x;
    cin >> n >> q >> x;

    int novo_n = pow(2, n);

    vector<int> niz(novo_n, 0);

    for(int i = 0; i < n; i++)
        cin >> niz[i];

    int visina = ceil(log2(novo_n));
    int velicina = 2*pow(2, visina);

    vector<int> drvo(velicina);
    vector<int> brojac(velicina);

    formiraj1(drvo, niz, 1, 0, novo_n-1, x);
    formiraj2(brojac, niz, 1, 0, novo_n-1, x);

    int k, v, a, b;

    for(int i = 0; i < q; i++){
        cin >> k >> v >> a >> b;

        izmeni1(drvo, 1, 0, novo_n-1, k, v, x);
        izmeni2(brojac, 1, 0, novo_n-1, k, v, x);

        cout << suma1(drvo, 1, 0, novo_n-1, a, b) << " " << suma2(brojac, 1, 0, novo_n-1, a, b) << endl;
    }


    return 0;
 }

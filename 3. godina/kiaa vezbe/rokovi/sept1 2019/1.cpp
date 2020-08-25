/* Anica je počela da uči programiranje. Kao zadatak je dobila niz
 * od 2^n celobrojnih vrednosti. Neka to bude niz a. Anica trenutno
 * uči bitovske operatore i zadatak joj je da za niz a odredi vrednost
 * v. Ta vrednost se računa u nekoliko iteracija. U prvoj iteraciji
 * kreira novi niz tako što računa bitovsko ili za susedne brojeve
 * takve da je prvi indeks paran a drugi neparan. Na primer, za niz
 * 1 2 3 4 računa 1 ili 2, 3 ili 4 i dobija niz 3 7. U sledećem
 * koraku računa bitovsku ekskluzivnu disjunkciju na isti način. Od
 * niza 3 7 dobija broj 4. Ovaj postupak se ponavlja dok se ne dobije
 * 1 broj koji predstavlja broj v. Kako zadatak ne bi bio previše
 * jednostavan Anica dobija još q upita oblika p b kojima se menja niz
 * tako što se element niza a p postavlja na vrednost b. Recimo ako
 * je upit 2 6, element na indeksu 2 postaje 6. Sa standardnog ulaza
 * se unosi broj n a zatim i broj q. U sledećoj liniji se unosi 2^n
 * celih brojeva koji predstavljaju elemente niza a. Nakon toga se u
 * narednih q linija unose upiti. Na standardni izlaz ispisati q brojeva
 * koji predstavljaju vrednost broja v nakon svakog od q upita. Složenost
 * algoritma treba da bude O(NlogN) gde N predstavlja 2^n. */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

void napravi_drvo(const vector<int>& niz, vector<int>& drvo, int k, int x, int y, int i){
    if(x == y){
        drvo[k] = niz[x];
        return;
    }

    int sr = (x + y) / 2;

    napravi_drvo(niz, drvo, 2*k, x, sr, i^1);
    napravi_drvo(niz, drvo, 2*k+1, sr+1, y, i^1);

    if(i)
        drvo[k] = drvo[2*k] | drvo[2*k+1];
    else
        drvo[k] = drvo[2*k] ^ drvo[2*k+1];
}

void azuriraj_drvo(vector<int>& drvo, int k, int x, int y, int ind, int vr, int i){
    if(x == y){
        drvo[k] = vr;
        return;
    }

    int sr = (x + y) / 2;

    if(ind <= sr)
        azuriraj_drvo(drvo, 2*k, x, sr, ind, vr, i^1);
    else
        azuriraj_drvo(drvo, 2*k+1, sr+1, y, ind, vr, i^1);

    if(i)
        drvo[k] = drvo[2*k] | drvo[2*k+1];
    else
        drvo[k] = drvo[2*k] ^ drvo[2*k+1];
}

int main(){

    int n, q;
    cin >> n >> q;

    vector<int> niz;
    int x;

    int novo_n = pow(2, n);

    for(int i = 0; i < novo_n; i++){
        cin >> x;
        niz.push_back(x);
    }

    vector<pair<int, int>> upiti;

    int p, b;
    for(int i = 0; i < q; i++){
        cin >> p >> b;
        upiti.push_back({p-1, b});
    }

    int visina = ceil(log2(novo_n));
    int velicina = 2*pow(2, visina);

    vector<int> drvo(velicina);

    napravi_drvo(niz, drvo, 1, 0, novo_n-1, n % 2);

    for(pair<int, int>& u : upiti){
        azuriraj_drvo(drvo, 1, 0, novo_n-1, u.first, u.second, n % 2);
        cout << drvo[1] << endl;
    }

    return 0;
}

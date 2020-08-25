/* Domine se slazu jedna uz drugu, tako sto se polja na dominama
 * postavljenim jednu uz drugu moraju poklapati. Domine obicno
 * imaju samo dva polja, medjutim, nase su domine specijalne i
 * imaju vise razlicitih polja (oznacenih slovima). Ako sve
 * domine koje slazemo imaju istu saru, napisi program koji
 * odredjuje kako je domine moguce sloziti tako da zauzmu sto
 * manje prostora po duzini (svaka naredna domina mora biti
 * smaknuta bar za jedno polje). Na primer,
    ababcabab
         ababcabab
              ababcabab */

#include<iostream>
#include<vector>
using namespace std;

void kmpPreprocesiraj(const string& p, vector<int>& b){
    int m = b.size();
    int i = 0, j = -1;

    b[i] = j;

    while(i < m){
        while(j >= 0 && p[i] != p[j])
            j = b[j];

        i++;
        j++;
        b[i] = j;
    }
}

int main(){

    string rec;
    cin >> rec;

    int n;
    cin >> n;

    int m = rec.size();

    vector<int> b(m+1);

    kmpPreprocesiraj(rec, b);

    cout << b[m] + n*(m - b[m]) << endl;

    return 0;
}

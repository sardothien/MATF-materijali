/* Reč w je periodična ako postoji neprazna reč p = p1p2 i prirodan
 * broj n ≥ 2 tako da je w = p^np1. Na primer, reč abacabacabacab
 * je periodična jer se ponavlja abac, pri čemu se poslednje ponavljanje
 * ne završava celo već se zaustavlja sa ab, tj. reč je (abac)^3ab.
 * Napisati program koji proverava da li je uneta reč periodična. */

#include<iostream>
#include<vector>
using namespace std;

void kmpPreprocesiraj(const string &p, vector<int> &b){
    int m = b.size(), i = 0, j = -1;

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

    int m = rec.size();
    vector<int> b(m+1);

    kmpPreprocesiraj(rec, b);
    if(2*b[m] >= m)
        cout << "Jeste periodicna" << endl;
    else
        cout << "Nije periodicna" << endl;

    return 0;
}

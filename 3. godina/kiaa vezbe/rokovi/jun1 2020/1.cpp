/* Data je niska S i ceo broj x. Potrebno je odrediti najduzu
 * podnisku niske S koja je palindrom i dugacka je barem x
 * karaktera. Napisati program koji odredjuje takvu podnisku.
 * Sa standardnog ulaza se ucitava niska S i zatim broj x. Na
 * standardni izlaz ispisati duzinu trazene podniske, a zatim
 * i samu podnisku u istoj liniji, razdvojene razmakom. Ukoliko
 * postoji vise takvih podniski ispisati poslednju, a ukoliko
 * ne postoji nijedna ispisati -1. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void manacer(string& s, int x){
    int n = s.size();

    string rec = "$";
    for(int i = 0; i < n; i++){
        rec += "#";
        rec += s[i];
    }
    rec += "#@";

    n = rec.size();

    int C = 1, R = 1;
    int mirror;

    vector<int> pom(n);

    for(int i = 1; i < n-1; i++){
        mirror = 2*C - i;

        if(i < R)
            pom[i] = min(R-i, pom[mirror]);

        while(rec[i + (pom[i]+1)] == rec[i - (pom[i]+1)])
            pom[i]++;

        if(i + pom[i] > R){
            R = i + pom[i];
            C = i;
        }
    }

    int max_pos;
    int max = 0;

    for(int i = 0; i < pom.size(); i++)
        if(max <= pom[i]){
            max = pom[i];
            max_pos = i;
        }

    int pocetak = max_pos - max + 1;
    int kraj = pocetak + 2*max;

    string rez = "";
    for(int i = pocetak; i < kraj; i += 2)
        rez += rec[i];

    if(rez.size() > x)
        cout << rez.size() << " " << rez << endl;
    else
        cout << "-1" << endl;
}

int main(){

    string rec;
    cin >> rec;

    int x;
    cin >> x;

    manacer(rec, x);

    return 0;
}

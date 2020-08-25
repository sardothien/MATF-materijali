#include<iostream>
#include<vector>
using namespace std;

void kmpPreprocesiraj(const string& p, vector<int> &b){
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

void kmpTrazi(const string &t, const string &p, vector<int> b){
    int n = t.size(), m = p.size();
    int j = 0, i = 0;

    while(i < n){
        while(j >= 0 && t[i] != p[j])
            j = b[j];
        i++;
        j++;

        if(j == m){
            cout << i-j << endl;
            b[i] = j;
        }
    }
}

int main(){

    string tekst = "abrakadabra";
    string uzorak = "ra";

    int m = uzorak.size();
    vector<int> b(m+1);

    kmpPreprocesiraj(uzorak, b);

    kmpTrazi(tekst, uzorak, b);

    return 0;
}

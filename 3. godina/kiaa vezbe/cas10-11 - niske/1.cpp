/* Napisati funkciju za hesiranje niske. */

#include<iostream>
using namespace std;

int hes(string& s){
    
    int p = 31;
    int m = 1e9+9;
    long long hes_vrednost = 0;
    
    int n = s.size();
    
    for(int i = n-1; i >= 0; i--)
        hes_vrednost = (hes_vrednost * p + (s[i]-'a'+1)) % m;
    
    return hes_vrednost;
}

int main(){
    
    string s;
    cin >> s;
    
    cout << hes(s) << endl;
    
    return 0;
}

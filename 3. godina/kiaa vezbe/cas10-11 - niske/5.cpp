/* Za dati tekst T = t0t1...tn−1 i uzorak P = p0p1...pm−1
 * ustanoviti da li postoji segment niske T jednak P, a 
 * ako postoji, pronaći sva njegova pojavljivanja u tekstu. */

#include<iostream>
#include<vector>
using namespace std;

void rabinKarp(string& pattern, string& text){
    
    int M = pattern.size();
    int N = text.size();
    int p = 31;
    int m = 1e9+9;
    
    vector<long long> pStepen(max(M, N));
    pStepen[0] = 1;
    
    for(int i = 1; i < pStepen.size(); i++)
        pStepen[i] = (pStepen[i-1] * p) % m;
    
    vector<long long> hes(N+1, 0);
    
    for(int i = 0; i < N; i++)
        hes[i+1] = (hes[i] + (text[i]-'a'+1)*pStepen[i]) % m;
    
    long long hesUzorka = 0;
    for(int i = 0; i < M; i++)
        hesUzorka = (hesUzorka + (pattern[i]-'a'+1)*pStepen[i]) % m;
    
    vector<int> pojavljivanja;
    for(int i = 0; i <= N-M; i++){
        long long h = (hes[i+M] + m - hes[i]) % m;
        if(h == (hesUzorka * pStepen[i]) % m)
            pojavljivanja.push_back(i);
    }
    
    for(int i = 0; i < pojavljivanja.size(); i++)
        cout << pojavljivanja[i] << " ";
    cout << endl;
}

int main(){
    
    string text, pattern;
    cin >> text >> pattern;
    
    rabinKarp(pattern, text);
    
    return 0;
}

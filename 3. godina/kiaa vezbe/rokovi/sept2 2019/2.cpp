/* Neka je zadata niska S. Pronaći ukupan broj palindromskih podniski niske S.
 * Sa standarnog ulaza se unosi niska S. Na standardni izlaz ispisati jedan
 * broj koji predstavlja broj palindromskih podniski niske S. */

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

void manacer(string& S, int *brojac){
    
    int n = S.size();
    
    string pom = "$";
    for(int i = 0; i < n; i++){
        pom += "#";
        pom += S[i];
    }
    pom += "#@";
    
    n = pom.size();    
    vector<int> pom_vektor(n);
    
    int C = 1, R = 1;
    int mirror;
    
    for(int i = 1; i < n-1; i++){
        mirror = 2*C - i;
        
        if(i < R)
            pom_vektor[i] = min(R-i, pom_vektor[mirror]);
        
        while(pom[i + (pom_vektor[i]+1)] == pom[i - (pom_vektor[i]+1)])
            pom_vektor[i]++;
        
        *brojac += ceil(pom_vektor[i] / 2.0);
        
        if(i + pom_vektor[i] > R){
            R = i + pom_vektor[i];
            C = i;
        }
    }
}

int main(){
    
    string S;
    cin >> S;
    
    int br = 0;
    
    manacer(S, &br);
    
    cout << br << endl;
    
    return 0;
}

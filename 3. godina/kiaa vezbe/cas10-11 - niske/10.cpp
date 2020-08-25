/* Domine se slazu jedna uz drugu tako sto se polja na 
 * dominama postavljenim jednu uz drugu moraju poklapati. 
 * Domine obicno imaju samo dva polja, medjutim, nase su 
 * specijalne i imaju vise razlicitih polja. Ako sve domine 
 * koje slazemo imaju istu saru, napisi program koji odredjuje 
 * kako je domine moguce sloziti tako da zauzmu sto manje prostora  
 * po duzini. */

#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    int n;
    cin >> n;
    
    vector<int> kmp(s.size()+1);
    kmp[0] = -1;
    
    for(int i = 0; i < s.size(); i++){
        int k = i;
        
        while(k > 0 && s[i] != s[kmp[k]])
            k = kmp[k];
        
        kmp[i+1] = kmp[k] + 1;
    }
    
    cout << kmp[s.size()] + n*(s.size() - kmp[s.size()]) << endl;
    
    return 0;
}

/* Data je lista od n niski s1, s2,..., sn od kojih je 
 * svaka dužine maksimalno m. Pronaći sve duplikate među
 * niskama i podeliti ih na grupe jednakih niski. */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long izracunajHes(const string& s){
    int p = 31;
    int m = 1e9 + 9;
    long long hesVrednost = 0;
    
    for(int i = s.size()-1; i >= 0; i--)
        hesVrednost = (hesVrednost*p + (s[i] - 'a' + 1)) % m;
    
    return hesVrednost;
}

void grupisiIsteNiske(const vector<string> niske){
    int n = niske.size();
    vector<pair<long long, int>> heshevi(n);
    
    for(int i = 0; i < n; i++)
        heshevi[i] = { 
            izracunajHes(niske[i]), i
        };
    
    sort(heshevi.begin(), heshevi.end());
    
    vector<vector<int>> grupe;
    int j = 0;
    
    for(int i = 0; i < n; i++){
        if(i == 0 || heshevi[i].first != heshevi[i-1].first){
            vector<int> novaGrupa;
            grupe.push_back(novaGrupa);
        }
        grupe.back().push_back(heshevi[i].second);
    }
    
    for(int i = 0; i < grupe.size(); i++){
        cout << "Grupa broj " << i << ":" << endl;
        for(int j = 0; j < grupe[i].size(); j++)
            cout << niske[grupe[i][j]] << " ";
        cout << endl;
    }
}

int main(){
    
    int n;
    cin >> n;
    
    vector<string> niske(n);
    
    for(int i = 0; i < n; i++)
        cin >> niske[i];
    
    grupisiIsteNiske(niske);
    
    return 0;
}

/* Implementirati Manacherov algoritam za odredjivanje 
 * najduze palindromske podniske niske S. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void manacer(string& s){
    
    int n = s.size();
    
    string pom = "$";
    for(int i = 0; i < n; i++){
        pom += "#";
        pom += s[i];
    }
    pom += "#@";
    
    int C = 1, R = 1;
    
    n = pom.size();
    vector<int> pom_vector(n);
    
    int mirror;
    
    for(int i = 1; i < n-1; i++){
        mirror = 2*C - i;
        
        if(i < R)
            pom_vector[i] = min(R-i, pom_vector[mirror]);
        
        while(pom[i + (pom_vector[i]+1)] == pom[i - (pom_vector[i]+1)])
            pom_vector[i]++;
        
        if(i + pom_vector[i] > R){
            R = i + pom_vector[i];
            C = i;
        }
    }
    
    int max_pos = max_element(pom_vector.begin(), pom_vector.end()) - pom_vector.begin();
    int max = pom_vector[max_pos];
    
    int start = max_pos - max + 1;
    int end = start + 2*max;
    
    string rez = "";
    for(int i = start; i < end; i += 2)
        rez += pom[i];
    
    cout << rez << endl;
}

int main(){
    
    string s = "cabaabad";
    
    manacer(s);
    
    return 0;
}

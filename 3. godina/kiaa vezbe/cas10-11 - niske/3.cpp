/* Implementirati algoritam KMP za proveru da li se 
 * neka niska S nalazi u tekstu P. */

#include<iostream>
#include<vector>
using namespace std;

void izracunajPrefixTabel(string& pattern, vector<int>& prefix_table, int n){
    
    prefix_table[0] = 0;
    
    int i = 1;
    int j = 0;
    
    while(i < n){
        if(pattern[i] == pattern[j]){
            prefix_table[i] = j+1;
            i++;
            j++;
        }
        else{
            if(j != 0)
                j = prefix_table[j-1];
            else{
                prefix_table[i] = 0;
                i++;
            }
        }
    }
    
    for(char c : pattern)
        cout << c << " ";
    cout << endl;
    
    for(int x : prefix_table)
        cout << x << " ";
    cout << endl;
}

void kmp(string& text, string& pattern){
    
    int n = text.size();
    int m = pattern.size();
    
    vector<int> prefix_table(m);
    
    izracunajPrefixTabel(pattern, prefix_table, m);
    
    int i = 0, j = 0;
    
    while(i < n){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }
        
        if(j == m){
            cout << "Pronadjena je podniska!" << endl;
            cout << i-m << endl;
            return;
        }
        
        if(i < n && pattern[j] != text[i]){
            if(j != 0)
                j = prefix_table[j-1];
            else
                i++;
        }
    }
    
    cout << "Nije pronadjena podniska!" << endl;
}

int main(){
    
    string text = "abcabcabcabcabcabcabcd";
    string pattern = "abcabcabcd";
    
    kmp(text, pattern);
    
    return 0;
}

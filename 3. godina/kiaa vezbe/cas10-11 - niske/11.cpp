/* Ниска дужине n се циклично помера за једно место у лево тако
 * што се њен почетни карактер са почетка пребаци на крај. Након
 * n цикличних померања ниска се враћа у почетни положај. Са 
 * стандардног улаза се учитава ниска састављена само од малих 
 * слова енглеске абецеде. На стандардни излаз исписати колико 
 * је њених цикличних померања једнако почетној ниски. */

#include<iostream>
#include<vector>
using namespace std;

int main(){
    
    string s;
    cin >> s;
    
    vector<int> kmp(s.size()+1, 0);
    kmp[0] = -1;
    
    for(int i = 0; i < s.size(); i++){
        int k = i;
        
        while(k > 0 && s[i] != s[kmp[k]])
            k = kmp[k];
        
        kmp[i+1] = kmp[i] + 1;
    }
    
    string ss = s + s;
    
    int br = 0;
    int i = 0, j = 0;
    
    while(i < ss.size()){
        if(ss[i] == s[j]){
            i++;
            j++;
            
            if(j == s.size()){
                br++;
                j = kmp[j];
            }
        }
        else if(j == 0)
            i++;
        else
            j = kmp[j];
    }
    
    cout << br-1 << endl;
    
    
    return 0;
}

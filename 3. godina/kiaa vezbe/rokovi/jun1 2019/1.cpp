/* Дат је скуп који садржи N природних бројева. Нађи највећи
 * подскуп такав да за било који пар елемената A и B из тог
 * подскупа или A дели B или B дели A. У првом реду стандардног
 * улаза дат је цео број N. У другој линији дато је N чланова
 * скупа (све вредности су између 1 и 109). На стандарни излаз
 * исписати један цео број који представља број чланова жељеног скупа. */

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> skup(n);

    for(int i = 0; i < n; i++)
        cin >> skup[i];

    sort(skup.begin(), skup.end());

    vector<int> podskup(n, 0);

    for(int i = 0; i < n; i++){
        int najbolje = 0;

        for(int j = 0; j < i; j++){
            if(skup[i] % skup[j] == 0 && najbolje <= podskup[j]){
                najbolje = podskup[j];
            }
        }

        podskup[i] = najbolje + 1;
    }

    cout << *max_element(podskup.begin(), podskup.end()) << endl;

    return 0;
}

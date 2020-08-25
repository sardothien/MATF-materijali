/* Дати су послови који сви трају јединично време и за
 * сваки посао је познато који је крајњи рок да се заврши
 * и колики је профит ако се тај посао заврши у року.
 * Напиши програм који одређује максимални профит који се
 * може остварити. Улаз: Са стандардног улаза се учитава
 * број послова n (1<=n<=50000), а затим за сваки посао рок
 * завршетка (природан број од 1 до n) и профит (цео број од
 * 1 до 100). Излаз: На стандардни излаз исписати максимални
 * профит. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dsu_init(int n, vector<int>& roditelj){
    roditelj = vector<int>(n);

    for(int i = 0; i < n; i++)
        roditelj[i] = i;
}

int dsu_find(int x, vector<int>& roditelj){
    while(x != roditelj[x]){
        roditelj[x] = roditelj[roditelj[x]];
        x = roditelj[x];
    }

    return x;
}

void dsu_union(int x, int y, vector<int>& roditelj){
    roditelj[x] = y;
}

int main(){

    int n;
    cin >> n;

    vector<pair<int, int>> poslovi(n);

    for(int i = 0; i < n; i++)
        cin >> poslovi[i].first >> poslovi[i].second;

    sort(poslovi.begin(), poslovi.end(), [](const auto& p1, const auto& p2){
         return p1.second > p2.second;
    });

    int profit = 0;
    int brRasporedjenih = 0;
    int maxRok = max_element(poslovi.begin(), poslovi.end())->first;

    vector<int> roditelj;

    dsu_init(maxRok+1, roditelj);

    for(const auto& posao : poslovi){
        int vreme = dsu_find(posao.first, roditelj);

        if(vreme > 0){
            profit += posao.second;

            dsu_union(vreme, dsu_find(vreme-1, roditelj), roditelj);

            brRasporedjenih++;

            if(brRasporedjenih == maxRok)
                break;
        }
    }

    cout << profit << endl;

    return 0;
}

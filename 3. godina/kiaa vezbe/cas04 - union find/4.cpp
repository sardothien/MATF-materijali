/* Dat je graf koji predstavlja elektricno kolo. Za svaku
 * vezu je dato u kom trenutku se gasi. Koliko je potrebno
 * da prodje vremena da ne bi bilo kratkog spoja (tj. da ne
 * bi bilo ciklusa u grafu)? */

#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
using namespace std;

void dsu_init(int n, vector<int>& roditelj, vector<int>& rank){
    roditelj = vector<int>(n);
    rank = vector<int>(n);

    for(int i = 0; i < n; i++)
        roditelj[i] = i;
}

int dsu_find(vector<int>& roditelj, int x){
    if(roditelj[x] == x)
        return x;

    return roditelj[x] = dsu_find(roditelj, roditelj[x]);
}

void dsu_union(vector<int>& roditelj, vector<int>& rank, int x, int y){
    x = dsu_find(roditelj, x);
    y = dsu_find(roditelj, y);

    if(x != y){
        if(rank[x] < rank[y])
            swap(x, y);
        if(rank[x] == rank[y])
            rank[x]++;

        roditelj[y] = x;
    }
}

int main(){

    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> grane(m);

    for(int i = 0; i < m; i++)
        cin >> get<0>(grane[i]) >> get<1>(grane[i]) >> get<2>(grane[i]);

    sort(grane.rbegin(), grane.rend());

    vector<int> roditelj, rank;
    dsu_init(n, roditelj, rank);

    for(auto grana : grane){
        int x = get<1>(grana);
        int y = get<2>(grana);

        if(dsu_find(roditelj, x) == dsu_find(roditelj, y)){
            cout << get<0>(grana) << endl;
            return 0;
        }

        dsu_union(roditelj, rank, x, y);
    }

    return 0;
}

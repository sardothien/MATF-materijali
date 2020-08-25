/* Implementacija union-find strukture. */

#include<iostream>
#include<vector>
using namespace std;

void dsu_init(int n, vector<int>& id, vector<int>& rank){
    id = vector<int>(n);
    rank = vector<int>(n);

    for(int i = 0; i < n; i++)
        id[i] = i;
}

int dsu_find(vector<int>& id, int x){
    if(id[x] == x)
        return x;

    return id[x] = dsu_find(id, id[x]);
}

void dsu_union(vector<int>& id, vector<int>& rank, int x, int y){
    x = dsu_find(id, x);
    y = dsu_find(id, y);

    if(x != y){
        if(rank[x] < rank[y])
            swap(x, y);
        if(rank[x] == rank[y])
            rank[x]++;
        id[y] = x;
    }
}

int main(){

    int n;
    cin >> n;

    vector<int> id, rank;
    dsu_init(n, id, rank);

    while(true){
        string command;
        cin >> command;

        if(command == "union"){
            int x, y;
            cin >> x >> y;
            dsu_union(id, rank, x, y);
        }
        else if(command == "find"){
            int x;
            cin >> x;
            cout << dsu_find(id, x) << endl;
        }
        else
            break;
    }

    return 0;
}

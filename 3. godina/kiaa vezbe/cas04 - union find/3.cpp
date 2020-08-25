/* Implementacija union-find strukture. */

#include<iostream>
#include<vector>
using namespace std;

void dsu_init(int n, vector<int>& id, vector<int>& size){
    id = vector<int>(n);
    size = vector<int>(n, 1);

    for(int i = 0; i < n; i++)
        id[i] = i;
}

int dsu_find(vector<int>& id, int x){
    if(id[x] == x)
        return x;

    return id[x] = dsu_find(id, id[x]);
}

void dsu_union(vector<int>& id, vector<int>& size, int x, int y){
    x = dsu_find(id, x);
    y = dsu_find(id, y);

    if(x != y){
        if(size[x] < size[y])
            swap(x, y);

        id[y] = x;
        size[x] += size[y];
    }
}

int main(){

    int n;
    cin >> n;

    vector<int> id, size;
    dsu_init(n, id, size);

    while(true){
        string command;
        cin >> command;

        if(command == "union"){
            int x, y;
            cin >> x >> y;
            dsu_union(id, size, x, y);
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

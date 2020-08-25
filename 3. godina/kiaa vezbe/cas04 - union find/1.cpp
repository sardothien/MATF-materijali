/* Implementacija union-find strukture. */

#include<iostream>
#include<vector>
using namespace std;

vector<int> dsu_init(int n){
    vector<int> id(n);

    for(int i = 0; i < n; i++)
        id[i] = i;

    return id;
}

int dsu_find(vector<int>& id, int x){
    while(x != id[x])
        x = id[x];

    return x;
}

void dsu_union(vector<int>& id, int x, int y){
    x = dsu_find(id, x);
    y = dsu_find(id, y);

    if(x != y)
        id[y] = x;
}

int main(){

    int n;
    cin >> n;

    vector<int> id = dsu_init(n);

    while(true){
        string command;
        cin >> command;

        if(command == "union"){
            int x, y;
            cin >> x >> y;
            dsu_union(id, x, y);
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

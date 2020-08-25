/* Логичка матрица димензије nxn у почетку садржи све нуле.
 * Након тога се насумично додаје једна по једна јединица.
 * Кретање по матрици је могуће само по јединицама и то само
 * на доле, на горе, на десно и на лево. Написати програм који
 * учитава димензију матрице, а затим позицију једне по једне
 * јединице и одређује након колико њих је први пут могуће сићи
 * од врха до дна матрице (са произвољног поља прве врсте до
 * произвољног поља последње врсте матрице). Улаз: Са стандардног
 * улаза се учитава димензија матрице 1<=n<=200, затим број поља m
 * (1<=m<=n^2) у које се уписује јединица, а затим у наредних m редова
 * координате тих поља (број врсте и број колоне од 0 до n−1, раздвојени
 * размаком). Излаз: На стандардни излаз исписати број x. x је редни
 * број јединице након чијег уноса је први пут могуће сићи од врха до
 * дна матрице. */

#include<iostream>
#include<vector>
using namespace std;

// redni broj elementa (x, y) u matrici
int kod(int x, int y, int n){
    return x*n + y;
}

void dsu_init(int n, vector<int>& roditelj, vector<int>& rank){
    roditelj = vector<int>(n);
    rank = vector<int>(n);

    for(int i = 0; i < n; i++){
        roditelj[i] = i;
        rank[i] = 0;
    }
}

int dsu_find(int x, vector<int>& roditelj){
    while(x != roditelj[x]){
        roditelj[x] = roditelj[roditelj[x]];
        x = roditelj[x];
    }

    return x;
}

void dsu_union(int x, int y, vector<int>& roditelj, vector<int>& rank){
    x = dsu_find(x, roditelj);
    y = dsu_find(y, roditelj);

    if(rank[x] < rank[y])
        roditelj[x] = y;
    else if(rank[y] < rank[x])
        roditelj[y] = x;
    else{
        roditelj[x] = y;
        rank[y]++;
    }
}

int main(){

    int n;
    cin >> n;

    vector<vector<bool>> matrica(n);
    for(int i = 0; i < n; i++)
        matrica[i].resize(n, false);

    int izvor = n*n;
    int usce = n*n+1;

    vector<int> roditelj, rank;

    dsu_init(n*n+2, roditelj, rank);

    for(int i = 0; i < n; i++)
        dsu_union(izvor, kod(0, i, n), roditelj, rank);

    for(int i = 0; i < n; i++)
        dsu_union(kod(n-1, i, n), usce, roditelj, rank);

    int m;
    cin >> m;

    int korak = -1;

    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;

        if(matrica[x][y])
            continue;

        matrica[x][y] = true;

        if(x > 0 && matrica[x-1][y])
            dsu_union(kod(x, y, n), kod(x-1, y, n), roditelj, rank);
        if(x+1 < n && matrica[x+1][y])
            dsu_union(kod(x, y, n), kod(x+1, y, n), roditelj, rank);
        if(y > 0 && matrica[x][y-1])
            dsu_union(kod(x, y, n), kod(x, y-1, n), roditelj, rank);
        if(y+1 < n && matrica[x][y+1])
            dsu_union(kod(x, y, n), kod(x, y+1, n), roditelj, rank);

        if(dsu_find(izvor, roditelj) == dsu_find(usce, roditelj)){
            korak = i;
            break;
        }
    }

    cout << korak << endl;

    return 0;
 }

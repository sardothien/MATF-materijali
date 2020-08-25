/* Neka je data binarna matrica (svi elementi su ili 0 ili 1). Koristeci
 * prefiksna stabla pronaci i ispisati redne brojeve svih vrsta koje se
 * javljaju kao duplikati. Ako su npr. vrste 3 i 5 iste ispisati samo 5. */

#include<iostream>
#include<vector>
using namespace std;

struct cvor {
    cvor() {
        br = 0;
        grane[0] = grane[1] = nullptr;
    }

    int br;
    cvor* grane[2];
};

void umetniRed(cvor* drvo, vector<int>& red, int n, int i, int broj){
    if(i == n){
        drvo->br++;
        if(drvo->br > 1)
            cout << broj << endl;
        return;
    }

    if(drvo->grane[red[i]] == nullptr)
        drvo->grane[red[i]] = new cvor();

    umetniRed(drvo->grane[red[i]], red, n, i+1, broj);
}

int main(){

    vector<vector<int>> matrica = {
        {1, 0, 0, 1, 0},
		{0, 1, 1, 0, 0},
		{1, 0, 0, 1, 0},
		{0, 0, 1, 1, 0},
		{0, 1, 1, 0, 0}
    };

    cvor* drvo = new cvor();

    int n = 5;

    for(int i = 0; i < n; i++)
        umetniRed(drvo, matrica[i], n, 0, i+1);

    return 0;
}

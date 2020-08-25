/* Neka je dato n binarnih brojeva. Koristeci prefiksna stabla pronaci
 * maksimalni broj koji se moze dobiti XOR-ovanjem (ekskluzivna disjunkcija)
 * ovih brojeva. */

#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

struct cvor {
    cvor() {
        krajKljuca = false;
        grane[0] = grane[1] = nullptr;
    }

    bool krajKljuca;
    cvor* grane[2]; // 0 ili 1
};

void umetni(cvor* drvo, const string& w, int i){
    if(i == w.size()){
        drvo->krajKljuca = true;
        return;
    }

    if(drvo->grane[w[i]-'0'] == nullptr)
        drvo->grane[w[i]-'0'] = new cvor();

    umetni(drvo->grane[w[i]-'0'], w, i+1);
}

void nadjiXOR(cvor* drvo, string& XOR, string& broj, int i){

    if(drvo->krajKljuca)
        return;

    int cifra = broj[i]-'0';

    if(drvo->grane[abs(cifra-1)]){
        XOR += '1';
        nadjiXOR(drvo->grane[abs(cifra-1)], XOR, broj, i+1);
    }
    else{
        XOR += '0';
        nadjiXOR(drvo->grane[cifra], XOR, broj, i+1);
    }
}

int vrednost(string& XOR){
    int n = XOR.size();
    int vr = 0;

    for(int i = 0, j = n-1; i < n; i++, j--)
        vr += pow(2, i) * (XOR[j]-'0');

    return vr;
}

int main(){

    vector<string> brojevi = {
        "001", "010", "011", "100", "101", "110", "111"
    };

    cvor* drvo = new cvor();

    int max = 0;
    string maxXOR;
    string XOR;

    for(auto s : brojevi){
        XOR = "";
        umetni(drvo, s, 0);

        nadjiXOR(drvo, XOR, s, 0);

        if(vrednost(XOR) > max){
            max = vrednost(XOR);
            maxXOR = XOR;
        }
    }

    cout << maxXOR << endl;

    return 0;
}

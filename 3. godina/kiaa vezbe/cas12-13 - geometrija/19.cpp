/* Neka je dato n segmenata na realnoj pravoj odredjenih svojim
 * pocetnim i krajnjim tackama. Odrediti sve segmente koji su
 * sadrzani u nekom drugom segmentu. */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Segment {
    int pocetak, kraj;
};

bool poredi(const Segment &t1, const Segment &t2){
    return t1.pocetak < t2.pocetak || (t1.pocetak == t2.pocetak && t1.kraj > t2.kraj);
}

void nadjiSveSegmente(vector<Segment> &segmenti){
    
    int max = segmenti[0].kraj;
    int n = segmenti.size();
    
    for(int i = 1; i < n; i++){
        if(segmenti[i].kraj <= max)
            cout << "[" << segmenti[i].pocetak << ", " << segmenti[i].kraj << "]\n";
        else
            max = segmenti[i].kraj;
    }
}


int main(){
    
    vector<Segment> segmenti = {
        {1, 2}, {1, 5}, {2, 7}, {3, 9},
        {2, 4}, {6, 8}, {5, 8}
    };
    
    sort(segmenti.begin(), segmenti.end(), poredi);
    
    nadjiSveSegmente(segmenti);
    
    return 0;
}

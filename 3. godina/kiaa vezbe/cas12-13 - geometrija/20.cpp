/* Neka je dato n segmenata na realnoj pravoj odredjenih 
 * svojim početnim i krajnjim tačkama. Odrediti dužinu 
 * unije svih segmenata. */
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

int unija(vector<Segment> &segmenti){
    int desno = segmenti[0].kraj;
    int suma = segmenti[0].kraj - segmenti[0].pocetak;
    int n = segmenti.size();
    
    for(int i = 1; i < n; i++){
        if(segmenti[i].kraj > desno){
            if(segmenti[i].pocetak > desno){
                suma += segmenti[i].kraj - segmenti[i].pocetak;
                desno = segmenti[i].kraj;
            }
            else{
                suma += segmenti[i].kraj - desno;
                desno = segmenti[i].kraj;
            }
        }
    }
    
    return suma;
}

int main(){
    
    vector<Segment> segmenti = {
        {1, 2}, {1, 5}, {2, 7}, {3, 9},
        {2, 4}, {6, 8}, {5, 8}
    };
    
    sort(segmenti.begin(), segmenti.end(), poredi);
    
    cout << unija(segmenti) << endl;
    
    return 0;
}

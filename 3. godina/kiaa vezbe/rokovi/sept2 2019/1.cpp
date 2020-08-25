/* Neka je dato N segmenata na veritkalnoj pravoj zadatih svojim krajnjim 
 * tačkama. Konstruisati algoritam složenosti O(nlogn) koji određuje 
 * koordinate krajnjih tačaka segmenta koji sadrži najveći broj drugih 
 * segmenata kao i broj sadržanih segmenata. Segment sadrži drugi segment
 * samo ako sadrži oba njegova kraja. Sa standarndnog ulaza se unosi broj N.
 * U narednih N linija se unose po 2 broja koja predstavljaju koordinate 
 * krajnjih tačaka segmenata. Na standardni izlaz ispisati koordinate traženog 
 * segmenta u opadajućem poretku a zatim i broj segmenata koje on sadrži. 
 * Može se pretpostaviti da je traženi segment jedinstven. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Segment {
public:
    Segment(int p, int k){
        pocetak = p;
        kraj = k;
    }
    
    int getPocetak() const { return pocetak; }
    int getKraj() const { return kraj; }
    
private:
    int pocetak, kraj;
};

bool poredi(const Segment& s1, const Segment& s2){
    if(s1.getPocetak() == s2.getPocetak())
        return s1.getKraj() < s2.getKraj();
    else
        return s1.getPocetak() > s2.getPocetak();
}

void sortiraj(vector<Segment>& segmenti){
    sort(segmenti.begin(), segmenti.end(), poredi);
}

void nadji_sve_segmente(vector<Segment>& segmenti){
    
    int max = segmenti[0].getKraj();
    
    int max_pocetak = segmenti[0].getPocetak();
    int max_kraj = segmenti[0].getKraj();
    
    int trenutni_pocetak = segmenti[0].getPocetak();
    int trenutni_kraj = segmenti[0].getKraj();
    
    int n = segmenti.size();
    int br = 0, max_segmenti = 0;
    
    for(int i = 1; i <= n; i++){
        if(i != n && segmenti[i].getKraj() >= max)
            br++;
        else{
            if(br > max_segmenti){
                max_segmenti = br;
                max_pocetak = trenutni_pocetak;
                max_kraj = trenutni_kraj;
            }
            
            trenutni_pocetak = segmenti[i].getPocetak();
            trenutni_kraj = segmenti[i].getKraj();
            
            br = 0;
            max = segmenti[i].getKraj();
        }
    }
    
    cout << max_pocetak << " " << max_kraj << " " << max_segmenti << endl;
}

int main(){
    
    int n;
    cin >> n;
    
    vector<Segment> segmenti;
    
    int x, y;
    
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        segmenti.push_back(Segment(x, y));
    }
    
    sortiraj(segmenti);
    
    nadji_sve_segmente(segmenti);    
    
    return 0;
}

/* Napisi program koji u nizu prirodnih brojeva odredjuje 
 * najveci broj koji se moze dobiti operacijom ekskluzivne 
 * disjunkcije primenjene na neki neprazni segment tog niza. */
// O(n)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct cvor {
    cvor() {
        grane[0] = grane[1] = nullptr;
    }
    
    cvor* grane[2];
};

void umetni(cvor* drvo, unsigned long long broj) {
    cvor* tmp = drvo;
    
    unsigned long long mask = 1ull << (8*sizeof(unsigned long long)-1);
    
    while(mask != 0){
        int bit = (broj & mask) != 0;
    
        if(tmp->grane[bit] == nullptr)
            tmp->grane[bit] = new cvor();
        
        tmp = tmp->grane[bit];
        mask >>= 1;
    }
}

unsigned long long maxXOR(cvor* drvo, unsigned long long broj) {
    cvor* tmp = drvo;
    
    unsigned long long rez = 0;
    unsigned long long mask = 1ull << (8*sizeof(unsigned long long)-1);
    
    while(mask != 0){
        int bit = (broj & mask) != 0;
        
        if(tmp->grane[!bit] != nullptr){
            rez = rez | mask;
            tmp = tmp->grane[!bit];
        }
        else
            tmp = tmp->grane[bit];
        
        mask >>= 1;
    }
    
    return rez;
}

int main(){
    
    // broj elemenata niza
    int n;
    cin >> n;
    
    unsigned long long broj;
    cin >> broj;
    
    unsigned long long xorPrefiksa = broj;
    
    cvor* drvo = new cvor();
    
    umetni(drvo, xorPrefiksa);
    
    unsigned long long maxSegmenta = xorPrefiksa;
    
    for(int i = 1; i < n; i++){
        cin >> broj;
        
        xorPrefiksa = xorPrefiksa ^ broj;
        
        maxSegmenta = max(maxSegmenta, xorPrefiksa);
        maxSegmenta = max(maxSegmenta, maxXOR(drvo, xorPrefiksa));
        
        umetni(drvo, xorPrefiksa);
    }
    
    cout << maxSegmenta << endl;
    
    return 0;
}

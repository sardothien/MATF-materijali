/* Napisi program koji medju unetim prirodnih brojevima odredjuje 
 * onaj par koji daje najveci rezultat pri operaciji XOR. */
// O(n)

#include<iostream>
using namespace std;

struct cvor {
    cvor(){
        grane[0] = grane[1] = nullptr;
    }
    
    // grana za 0 i 1
    cvor* grane[2];
};

void umetni(cvor* drvo, unsigned long long broj){
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

unsigned long long maxXOR(cvor* drvo, unsigned long long broj){
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
    
    // broj brojeva
    int n;
    cin >> n;
    
    unsigned long long broj;
    cin >> broj;
    
    cvor* drvo = new cvor();
    
    umetni(drvo, broj);
    
    unsigned long long max = 0;
    
    for(int i = 1; i < n; i++){
        cin >> broj;
        
        unsigned long long rez = maxXOR(drvo, broj);
        if(rez > max)
            max = rez;
        
        umetni(drvo, broj);
    }
    
    cout << max << endl;
    
    return 0;
}

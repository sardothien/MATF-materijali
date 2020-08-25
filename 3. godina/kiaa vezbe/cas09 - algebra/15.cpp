/* Dat je skup S sa celim brojevima i data su dva cela broja
 * x i y. Pronaci najveci zajednicki delilac brojeva x i y 
 * koji se nalazi u skupu S. */
// O(nlogn + q*sqrt(m)*log(n))

#include<iostream>
#include<set>
using namespace std;

int nzd(int a, int b){
    if(b == 0)
        return a;
    
    return nzd(b, a%b);
}

int main(){
    
    int n, q, x;
    cin >> n >> q;
    
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> x;
        s.insert(x);
    }
    
    while(q--){
        int a, b;
        cin >> a >> b;
        
        int d = nzd(a, b);
        int m = -1;
        
        for(int k = 1; k*k <= d; k++){
            if(d % k == 0){
                if(s.find(k) != s.end())
                    m = max(m, k);
                if(s.find(d/k) != s.end())
                    m = max(m, d/k);
            }
        }
        
        cout << m << endl;
    }
    
    return 0;
}

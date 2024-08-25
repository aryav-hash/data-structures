#include<bits/stdc++.h>
using namespace std;
class sieveOfEra{
    vector<int>sieve;
    public:
        bool prime(int n){
            sieve.resize(1e6+1, 1);
            sieve[1] = 0; // Setting.
            
            for (int i = 2; i * i <= n; i++){ // Iteration for primes.
                if (sieve[i]){ // If prime start updation.
                    for (int j = i * i; j <= n; j += i){
                        sieve[j] = 0; // update.
                    }
                }
            }
            
            if (sieve[n]){
                return true;
            }else{
                return false;
            }
        }    
};
int main(){
    int n;
    cin >> n;
    sieveOfEra obj;
    if (obj.prime(n)){
        cout << "Prime" << endl;
    }else{
        cout << "Not Prime" << endl;
    }
    return 0;
}

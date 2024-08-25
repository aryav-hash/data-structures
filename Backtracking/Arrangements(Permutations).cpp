#include<bits/stdc++.h>
using namespace std;
class arrangement{  // Backtracking Approach:-
    private:
    void f(int num, vector<int> &vis, int n){
        if (num > n){
            ans++;
            return;
        }
        
        for (int i = 1; i <= n; i++){
            if (!vis[i] && (num%i == 0 || i%num == 0)){ // Checking if the number is divisible or divides any index for permutation.
                vis[i] = true;
                f(num+1, vis, n);
                vis[i] = false; // Backtracking.
            }
        }
    }
    public:
    int ans;
    int sol(int n){
        ans = 0;
        vector<int> vis(n+1, 0); // Making a visited array for tracking.
        f(1, vis, n);
        return ans;
    }
};
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        arrangement obj;
        int ans = obj.sol(n);
        cout << ans << endl;
    }
    return 0;
}

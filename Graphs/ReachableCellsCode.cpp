#include <bits/stdc++.h>
using namespace std;

class NewYear {
public:
    vector<bool> sol(int n, vector<int>& arr) {
        vector<bool> reachable(n + 1, false);  // To track reachable cells
        queue<int> q;
        q.push(1);  // Start from cell 1
        reachable[1] = true;  // Mark cell 1 as reachable
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            // If the current cell can reach beyond the last cell, it shouldn't be processed
            if (current >= n) continue;
            
            int next = current + arr[current - 1];  // Calculate the next cell
            
            // If next cell is within bounds and not already visited
            if (next <= n && !reachable[next]) {
                reachable[next] = true;
                q.push(next);
            }
        }
        
        return reachable;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n - 1);
        for (int i = 0; i < n - 1; i++) {
            cin >> arr[i];
        }
        
        NewYear obj;
        vector<bool> vis = obj.sol(n, arr);
        
        int q;
        cin >> q;
        while (q--) {
            int des;
            cin >> des;
            if (vis[des]) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}

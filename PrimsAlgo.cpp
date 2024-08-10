#include<bits/stdc++.h>
using namespace std;

class primsAlgo{
public:
    int sol(int V, vector<vector<int>> adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        int sum = 0;
        pq.push({0, 0});
        while (!pq.empty()){
            auto pt = pq.top();
            pq.pop();
            int node = pt.second;
            int wt = pt.first;
            
            if (vis[node]) continue;

            vis[node] = 1;
            sum += wt;
            for (auto it : adj[node]){
                int adjNode = it[0];
                int adjWt = it[1];
                if (!vis[adjNode]){
                    pq.push({adjWt, adjNode});
                }
            }
        }
        return sum;
    } 
};

int main(){
    int t;
    cin >> t;
    while (t--){
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj[V];
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++){
            vector<int> temp(3);
            for (int i = 0; i < 3; i++){
                cin >> temp[i];
            }
            edges.push_back(temp);
        }

        for (auto it : edges){
            vector<int> tmp(2);
            tmp[0] = it[1];
            tmp[1] = it[2];
            adj[it[0]].push_back(tmp);
            tmp[0] = it[0];
            tmp[1] = it[2];
            adj[it[1]].push_back(tmp);
        }

        primsAlgo obj;
        int ans = obj.sol(V, adj);
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector <int> adj[], vector<bool>&vis){
    vis[node] = 1;
    cout << node << " ";
    for (auto it : adj[node]){
        if (!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

void dfsTraversal(int V, vector <int> adj[]){
    // code here:-
    vector<bool>vis(V, false);
    int start = 1;
    dfs(start, adj, vis);
}

int main(){
    int V, E;
    cin >> V >> E;
    vector<int>adj[V+1];
    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsTraversal(V, adj);
    return 0;
}

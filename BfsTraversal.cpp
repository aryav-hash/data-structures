#include <bits/stdc++.h>
using namespace std;

void bfsTraversal(int V, vector<int> adj[]){
    vector <bool> vis(V+1, false);
    queue <int> q;
    vis[1] = true;
    q.push(1);
    q.push(-1);
    while (!q.empty()){
        int node = q.front();
        q.pop();
        if (node == -1){
            cout << endl;
            if (!q.empty()){
                q.push(-1);
            }
        }
        else{
            cout << node << " ";
            for (auto it : adj[node]){
                if (!vis[it]){
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
    }
}

int main(){
    int V, E;
    cin >> V >> E;
    vector <int> adj[V+1];
    for (int i = 0; i < E; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfsTraversal(V, adj);
    return 0;
}

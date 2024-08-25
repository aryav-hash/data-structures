class Solution {
  private:
    void dfs(int node, vector<int>&vis, vector<vector<int>>adj[], stack <int> &stk){
        vis[node] = 1;
        for (auto it : adj[node]){
            int dirNode = it[0];
            if (!vis[dirNode]){
                dfs(dirNode, vis, adj, stk);
            }
        }
        stk.push(node);
    }
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here.
        vector<vector<int>> adj[N];
        for (auto it : edges){
            int node = it[0];
            int dirNode = it[1];
            int wt = it[2];
            vector<int> temp = {dirNode, wt};
            adj[node].push_back(temp);
        }
        
        // topological Sorting:-
        stack <int> stk;
        vector<int> vis(N, 0);
        for (int i = 0; i < N; i++){
            if (!vis[i]){
                dfs(i, vis, adj, stk);
            }
        }
        
        // calculating distance:-
        vector<int> dis(N, 1e9);
        dis[0] = 0;
        while (!stk.empty()){
            int node = stk.top();
            stk.pop();
            for (auto it : adj[node]){
                int dirNode = it[0];
                int wt = it[1];
                if (dis[node] + wt < dis[dirNode]){
                    dis[dirNode] = dis[node] + wt;
                }
            }
        }
        
        for (int i = 0; i < N; i++){
            if (dis[i] == 1e9){
                dis[i] = -1;
            }
        }
        
        return dis;
    }
};

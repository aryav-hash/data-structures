class Solution {
public:
    void dfs(int node, vector<int>adjlist[], vector<bool>&vis, int n){
        vis[node] = true;
        for (auto it : adjlist[node]){
            if (!vis[it]){
                dfs(it, adjlist, vis, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adjlist[n];
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (isConnected[i][j] == 1 && i != j){
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
            }
        }
        // Using dfs algorithm to calculate provinces:-
        vector<bool>vis(n, false);
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                cnt++;
                dfs(i, adjlist, vis, n);
            }
        }
        return cnt;
    }
};

void dfs(int node, vector<bool>&vis, vector<int> adjList[], 
    stack <int> &stk){

    vis[node] = true;
    for (auto it : adjList[node]){
        if (!vis[it]){
            dfs(it, vis, adjList, stk);
        }
    }
    stk.push(node);
}
vector<int> topoSort(int V, vector<int> adjList[]){
    vector<bool>vis(V, false);
    stack <int> stk;

    for (int i = 0; i < V; i++){
        if (!vis[i]){
            dfs(i, vis, adjList, stk);
        }
    }

    vector<int>ans(V);
    while (!stk.empty()){
        ans.push_back(stk.top());
        stk.pop();
    }

    return ans;
}

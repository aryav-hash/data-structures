bool detect(int start, vector<int> adjList[], vector<int>&vis){
    queue<pair<int, int>> q;
    q.push({start, -1});
    vis[start] = 1;
    while (!q.empty()){
        int node = q.first;
        int parent = q.second;
        q.pop();
        for (auto adjNode : adjList[node]){
            if (!vis[adjNode]){
                q.push({adjNode, node});
                vis[adjNode] = 1;
            }
            else if (parent != adjNode){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adjList[]){
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++){
        if (!vis[i]){
            if(detect(i, adjList, vis)){
                return true;
            }
        }
    }
    return false;
}

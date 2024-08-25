bool detect(int node, vector<int>adjList[], vector<bool> &vis,
    vector<bool> &pathVis){
    vis[node] = true;
    pathVis[node] = true;
    
    for (auto adjNode : adjList[node]){
        if (!vis[adjNode]){
            if (detect(adjNode, adjList, vis, pathVis)){
                return true;
            }
        }
        else if (pathVis[adjNode]){
            return true;
        }
    }
    
    pathVis[node] = false;
    return false;
}
bool isCyclic(int V, vector<int>adjList[]){
    vector<bool> vis(V, false);
    vector<bool> pathVis(V, false);

    for (int i = 0; i < V; i++){
        if (!vis[i]){
            if (detect(i, adjList, vis, pathVis)){
                return true;
            }
        }
    }
    return false;
}

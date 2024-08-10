class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // n = nodes, m = edges, 0 based indexing of graph.
        vector<int> adj_list[N];
        for (auto it : edges){
            int u, v;
            u = it[0];
            v = it[1];
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        
        vector<int> dist(N, 1e9); // Update the distances of the node here.
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            
            for (auto adjNode : adj_list[node]){
                if (dist[node] + 1 < dist[adjNode]){  // if the distance of the adjNode is more than dist[node] + 1, then update it.
                    q.push(adjNode);
                    dist[adjNode] = dist[node] + 1;
                }
            }
        }
        
        for (int i = 0; i < N; i++){ // If any node is untraversed, then it can't be accessed thus we just update the distance as -1.
            if (dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};

#include<bits/stdc++.h>
using namespace std;

class dijkstraAlgo{
    
public:
    vector<int> sol(int V, vector<vector<int>> &edges, int src){
        vector<pair<int, int>> adjList[V+1];
        for (auto it : edges){
            int node = it[0];
            int adjNode = it[1];
            int wt = it[2];
            adjList[node].push_back({adjNode, wt});
            adjList[adjNode].push_back({node, wt});
        }
        
        vector<int> distance(V+1, 1e9);
        vector<int> parent(V+1);
        for (int i = 0; i < V+1; i++){
            parent[i] = i;
        }
        distance[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        while (!pq.empty()){
            auto c = pq.top();
            pq.pop();
            int node = c.second;
            int wt = c.first;
            
            for (auto it : adjList[node]){
                int adjNode = it.first;
                int eWt = it.second;
                if (eWt + wt < distance[adjNode]){
                    distance[adjNode] = eWt + wt;
                    parent[adjNode] = node;
                    pq.push({distance[adjNode], adjNode});
                }
            }
        }
        
        return parent;
    }
    
    void seq(int node, vector<int>&parent, vector<int>&ans){
        
        if (node != parent[node]){
            seq(parent[node], parent, ans);   
        }
        ans.push_back(node); 
    }
};

int main(){
    int V, E, src;
    cin >> V >> E >> src;
    vector<vector<int>> edges;
    for (int i = 0; i < E; i++){
        vector<int> tmp(3);
        for (int i = 0; i < 3; i++){
            cin >> tmp[i];
        }
        edges.push_back(tmp);
    }
    
    dijkstraAlgo obj;
    vector<int>parent = obj.sol(V, edges, src);
    
    vector<int> ans;
    obj.seq(V, parent, ans);
    
    for (auto it : ans){
        cout << it << " ";
    }
    
    return 0;
}

/*
	BIPARTITE GRAPHS :-
	Algorithm to check whether the we can color the components of the graph alternately with two different colors.
	Given an adjacency list of a graph adj of V no. of vertices having 0 based index. 
	Check whether the graph is bipartite or not.
*/

class Solution {
public:
    bool helper(int node, vector<int>&vis, vector<int>adj[]){
        queue<int>q;
        q.push(node);
        vis[node] = 0;
        while (!q.empty()){
            int newnode = q.front();
            q.pop();
            
            for (auto it : adj[newnode]){
                if (vis[it] == -1){
                    vis[it] = !vis[newnode];
                    q.push(it);
                }else if (vis[it] == vis[newnode]){
                    return false;
                }
            }
        }
        
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V, -1);
	    for (int i = 0; i < V; i++){
	        if (vis[i] == -1){
	            if (!helper(i, vis, adj)){
	                return false;
	            }
	        }
	    }
	    return true;
	}
};

// https://www.geeksforgeeks.org/problems/bipartite-graph/1

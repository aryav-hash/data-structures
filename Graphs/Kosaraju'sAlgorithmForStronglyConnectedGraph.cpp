/*
	KOSARAJU'S ALGORITHM
	Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, 
	Find the number of strongly connected components in the graph.
	Strongly connected components are segments in a graph where each node is reachable to one another.
*/

class Solution
{
    private:
    void dfs(int node, vector<int>&vis, vector<vector<int>>&adj, stack<int>&st){
        vis[node] = 1;
        for (auto it : adj[node]){
            if (!vis[it]){
                dfs(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    private:
    void dfs2(int node, vector<int>adjListRev[], vector<int>&vis){
        vis[node] = 1;
        for (auto it : adjListRev[node]){
            if (!vis[it]){
                dfs2(it, adjListRev, vis);
            }
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here.
        vector<int>vis(V, 0);
        stack<int>st;
        for (int i = 0; i < V; i++){
            if (!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        vector<int>adjListRev[V];
        for (int i = 0; i < V; i++){
            vis[i] = 0;
            for (auto it : adj[i]){
                adjListRev[it].push_back(i);
            }
        }
        
        int res = 0;
        while (!st.empty()){
            int node = st.top();
            st.pop();
            if (!vis[node]){
                res++;
                dfs2(node, adjListRev, vis);
            }
        }
        return res;
    }
};

// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

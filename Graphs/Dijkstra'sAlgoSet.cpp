#include<bits/stdc++.h>
#include<set>
using namespace std;

class dijkstraAlgo{
public:
    vector<int> sol(int V, vector<vector<int>> &edges){
        vector<pair<int, int>> adjList[V];
        for (auto it : edges){
            int node = it[0];
            int adjNode = it[1];
            int d = it[2];
            adjList[node].push_back({adjNode, d});
            adjList[adjNode].push_back({node, d});
        }

        set <pair<int, int>> st;
        vector<int> distance(V, 1e9);
        distance[0] = 0;
        st.insert({0, 0}); // distance, node.

        while (!st.empty()){
            auto c = *(st.begin());
            st.erase(c);
            int node = c.second;
            int d = c.first;
            for (auto it : adjList[node]){
                int adjNode = it.first;
                int dis = it.second;
                if (dis + d < distance[adjNode]){
                    if (distance[adjNode] != 1e9) 
                        st.erase({distance[adjNode], adjNode});

                    distance[adjNode] = dis + d;
                    st.insert({distance[adjNode], adjNode});
                }
            }
        }
        return distance;
    }
};

int main(){
    int V, E;
    cin >> V >> E;
    vector<vector<int>> edges;
    for (int i = 0; i < E ;i++){
        vector<int>tmp(3);
        for (int i = 0; i < 3; i++){
            cin >> tmp[i];
        }
        edges.push_back(tmp);
    }
    dijkstraAlgo obj;
    vector<int> ans = obj.sol(V, edges);
    for (int i = 0; i < V; i++){
        cout << i << " " << ans[i] << endl;
    }
    return 0;
}

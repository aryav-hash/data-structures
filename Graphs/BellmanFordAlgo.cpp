#include<bits/stdc++.h>
using namespace std;
class bellmanFordAlgo{
public:
    int sol(int V, int src, int des, vector<vector<int>> &edges){
        vector<int> distance(V+1, 1e9);
        distance[src] = 0;
        for (int i = 0; i < V-1; i++){
            int flag = 0;
            for (auto it : edges){
                int node = it[0];
                int adjNode = it[1];
                int wt = it[2];
                if (distance[node] != 1e9 && distance[node] + wt < distance[adjNode]){
                    distance[adjNode] = distance[node] + wt;
                    flag = 1;
                }
            }
            if (flag == 0){
                return distance[des];
            }
        }
        
        for (auto it : edges){
            int node = it[0];
            int adjNode = it[1];
            int wt = it[2];
            if (distance[node] != 1e9 && distance[node] + wt < distance[adjNode]){
                return 1e9;
            }
        }
        
        return distance[des];
    }
};
int main(){
    int t;
    cin >> t;
    while (t--){
        int V, E;
        cin >> V >> E;
        int src, des;
        cin >> src >> des;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++){
            vector<int>tmp(3);
            for (int j = 0; j < 3; j++){
                cin >> tmp[j];
            }
            edges.push_back(tmp);
        }
        bellmanFordAlgo obj;
        int ans = obj.sol(V, src, des, edges);
        cout << ans << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class disjointSetUnion{
    vector<int> size, parent;
public:
    disjointSetUnion(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for (int i = 0; i < n+1; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_v == ulp_u){
            return;
        }
        if (size[ulp_v] > size[ulp_u]){
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
        else{
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};
int main(){
    int t;
    cin >> t;
    while(t--){
        int V, E;
        cin >> V >> E;
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < E; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }
        
        disjointSetUnion dsu(V);
        int sum = 0;
        sort(edges.begin(), edges.end());
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (dsu.findUParent(u) != dsu.findUParent(v)){
                sum += wt;
                dsu.unionBySize(u, v); 
            }
        }
        cout << sum << endl;
    }
    return 0;
}

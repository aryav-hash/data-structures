#include<bits/stdc++.h>
using namespace std;
class disjointSetUnion{
    vector<int> rank, parent;
public:
    disjointSetUnion(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for (int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findUParent(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;

        if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        if (rank[ulp_v] > rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int main(){
    disjointSetUnion ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);
    if (ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    ds.unionByRank(3, 7);
    if (ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class disjointSetUnion{
    vector<int> size, parent;
public:
    disjointSetUnion(int n){
        size.resize(n+1, 1);
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
    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_v] < size[ulp_u]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
int main(){
    disjointSetUnion ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);
    if (ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    ds.unionBySize(3, 7);
    if (ds.findUParent(3) == ds.findUParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    return 0;
}

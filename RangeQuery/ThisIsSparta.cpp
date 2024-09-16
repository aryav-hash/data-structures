/*
	Good Question on Range Query Implementation.
	King Leonidas of Sparta is preparing his men and country for a war against the Persian King Xerxes. He has N soldiers with him and he has arranged them in a line at The Hot Gates. Let us number them from 1 to N. Leonidas will fight Xerxes' army for Q days, and each day he can send only one of his men to fight.

For each warrior, we know 2 traits: Strength and Cowardice. These are given to us in a form of integer. Each day, Leonidas can choose his warrior from a range Li to Ri, and he will choose the warrior with maximum Strength value. If there is more than one warrior having the same maximum Strength value, he will choose the warrior with minimum Cowardice value. If there is still more than 1 warrior with the same maximum Strength value and same minimum Cowardice value, he chooses the one with lower index in line.

King Leonidas is ready to lay his life for Sparta. You, his right hand man, have to help him save Sparta by helping him choose a warrior for each day.
*/

#include<bits/stdc++.h>
using namespace std;
vector<int>subTree;
void build(vector<int>&arr, vector<int>&brr, int start, int end, int index){
    if (start == end){
        subTree[index] = start;
        return;
    }
    int mid = start + (end - start)/2;
    build(arr, brr, start, mid, 2*index+1);
    build(arr, brr, mid+1, end, 2*index+2);
    int idx1 = subTree[2*index+1];
    int idx2 = subTree[2*index+2];
    if (arr[idx1] == arr[idx2]){
        if (brr[idx1] > brr[idx2]) {
            subTree[index] = idx2;
        }else{
            subTree[index] = idx1;
        }
    }else{
        if (arr[idx1] > arr[idx2]){
            subTree[index] = idx1;
        }else{
            subTree[index] = idx2;
        }
    }
}
void buildTree(vector<int>&arr, vector<int>&brr, int n){
    subTree.resize(4*n);
    build(arr, brr, 0, n-1, 0);
}

int query(int x, int y, int start, int end, int index, vector<int>&arr, vector<int>&brr){
    if (x > end || y < start){
        return -1;
    }

    if (start >= x && end <= y){
        return subTree[index];
    }
    int mid = start + (end - start)/2;
    int idx1 = query(x, y, start, mid, 2*index+1, arr, brr);
    int idx2 = query(x, y, mid+1, end, 2*index+2, arr, brr);
    if (arr[idx1] == arr[idx2]){
        if (brr[idx1] > brr[idx2]) {
            return idx2;
        }else{
            return idx1;
        }
    }else{
        if (arr[idx1] > arr[idx2]){
            return idx1;
        }else{
            return idx2;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int>brr(n);
    for (int i = 0; i < n; i++){
        cin >> brr[i];
    }
    buildTree(arr, brr, n);
    int q, x, y;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> x >> y;
        cout << query(x-1, y-1, 0, n-1, 0, arr, brr)+1 << endl;
    }
    return 0;
}

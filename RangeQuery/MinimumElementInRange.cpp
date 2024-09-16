/*
	Problem statement
You are given a sequence A[1], A[2], ..., A[N] of N numbers ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are Q queries, and each query is defined in either of the following two ways:

Query on range:

You are given two numbers i and j; the answer to each query is the minimum number between the range (i, j) (including both i and j). Note that in this query, i and j lies in the range: [1, N].

Update query:

You are given two numbers i and B; update A[i] to B. Note that in this query, i lies in the range: [1, N].
*/

#include<bits/stdc++.h>
using namespace std;

vector<int>subTree;

void build(int start, int end, int index, vector<int>&nums){
    if (start == end){
        subTree[index] = nums[start];
        return;
    }
    
    int mid = start + (end - start)/2;
    build(start, mid, 2 * index + 1, nums);
    build(mid + 1, end, 2 * index + 2, nums);
    subTree[index] = min(subTree[2 * index + 1], subTree[2 * index + 2]);
}

int query(int start, int end, int l, int r, int index){
    if (l > end || r < start){
        return INT_MAX;
    }
    
    if (start >= l && end <= r){
        return subTree[index];
    }
    
    int mid = start + (end - start)/2;
    int a = query(start, mid, l, r, 2 * index + 1);
    int b = query(mid + 1, end, l, r, 2 * index + 2);
    
    return min(a, b);
}

void update(int start, int end, int index, int ind, int e){
    if (start == end){
        subTree[index] = e;
        return;
    }
    
    int mid = start + (end - start)/2;
    if (ind <= mid){
        update(start, mid, 2 * index + 1, ind, e);
    }else{
        update(mid + 1, end, 2 * index + 2, ind, e);
    }
    
    subTree[index] = min(subTree[2 * index + 1], subTree[ 2 * index + 2]);
}

int main(){
    int n, q;
    cin >> n >> q;
    subTree.resize(n * 4);
    vector<int>nums(n);
    for (int i = 0; i < n; i++){
        cin >> nums[i];
    }
    build(0, n - 1, 0, nums);
    char ch;
    int l, r;
    for (int i = 0; i < q; i++){
        cin >> ch >> l >> r;
        
        if (ch == 'q'){
            cout << query(0, n - 1, l - 1, r - 1, 0) << endl;
        }else if (ch == 'u'){
            update(0, n - 1, 0, l - 1, r);
        }
    }
    return 0;
}

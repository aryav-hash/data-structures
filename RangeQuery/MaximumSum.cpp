/*
	Problem statement
You are given a sequence A[1], A[2], ..., A[N], ( 0 ≤ A[i] ≤ 10^8 , 2 ≤ N ≤ 10^5 ). There are two types of operations and they are defined as follows:

Update:

This will be indicated in the input of a 'U' followed by space and then two integers i and x.

U i x
This operation sets the value of A[i] to x.

Query:

This will be indicated in the input of a 'Q' followed by a single space and then two integers x and y.

Q x y
You must find two integers i and j such that x ≤ i, j ≤ y and i != j, such that the sum A[i]+A[j] is maximized. Print the sum A[i]+A[j].
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long max1; // Largest element in the range
    long long max2; // Second largest element in the range
};

vector<Node> segTree;

void buildTree(int index, int start, int end, vector<long long>& arr) {
    if (start == end) {
        // Leaf node will have a single element
        segTree[index].max1 = arr[start];
        segTree[index].max2 = LLONG_MIN; // Since only one element, second max is -infinity
    } else {
        int mid = (start + end) / 2;
        // Recursively build the segment tree
        buildTree(2 * index + 1, start, mid, arr);
        buildTree(2 * index + 2, mid + 1, end, arr);
        
        // Internal node will have the two largest elements from its children
        vector<long long> candidates = {
            segTree[2 * index + 1].max1,
            segTree[2 * index + 1].max2,
            segTree[2 * index + 2].max1,
            segTree[2 * index + 2].max2
        };
        sort(candidates.rbegin(), candidates.rend()); // Sort in descending order
        segTree[index].max1 = candidates[0];
        segTree[index].max2 = candidates[1];
    }
}

void updateTree(int index, int start, int end, int idx, long long value) {
    if (start == end) {
        // Leaf node
        segTree[index].max1 = value;
        segTree[index].max2 = LLONG_MIN;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            // If idx is in the left child, recurse on the left child
            updateTree(2 * index + 1, start, mid, idx, value);
        } else {
            // If idx is in the right child, recurse on the right child
            updateTree(2 * index + 2, mid + 1, end, idx, value);
        }
        // Internal node will have the two largest elements from its children
        vector<long long> candidates = {
            segTree[2 * index + 1].max1,
            segTree[2 * index + 1].max2,
            segTree[2 * index + 2].max1,
            segTree[2 * index + 2].max2
        };
        sort(candidates.rbegin(), candidates.rend());
        segTree[index].max1 = candidates[0];
        segTree[index].max2 = candidates[1];
    }
}

pair<long long, long long> queryTree(int index, int start, int end, int l, int r) {
    if (r < start || l > end) {
        // If the range is completely outside the current node's range
        return {LLONG_MIN, LLONG_MIN};
    }
    if (l <= start && end <= r) {
        // If the range is completely inside the current node's range
        return {segTree[index].max1, segTree[index].max2};
    }
    // If a part of the range overlaps with the current node's range
    int mid = (start + end) / 2;
    pair<long long, long long> left = queryTree(2 * index + 1, start, mid, l, r);
    pair<long long, long long> right = queryTree(2 * index + 2, mid + 1, end, l, r);
    
    // Merge results from left and right children
    vector<long long> candidates = {left.first, left.second, right.first, right.second};
    sort(candidates.rbegin(), candidates.rend());
    return {candidates[0], candidates[1]};
}

int main() {
    ios::sync_with_stdio(false); // Disable synchronization with C I/O
    cin.tie(nullptr); // Untie cin from cout for faster input/output

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Initialize the segment tree
    segTree.resize(4 * n);
    buildTree(0, 0, n - 1, arr);
    
    int q;
    cin >> q;
    while (q--) {
        char ch;
        int x, y;
        cin >> ch >> x >> y;
        if (ch == 'Q') {
            // Query
            pair<long long, long long> res = queryTree(0, 0, n - 1, x - 1, y - 1);
            cout << res.first + res.second << '\n';
        } else {
            // Update
            updateTree(0, 0, n - 1, x - 1, y);
        }
    }
    return 0;
}

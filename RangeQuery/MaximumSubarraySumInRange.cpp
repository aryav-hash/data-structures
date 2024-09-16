/*
	VVIMP Question of range query
	You are given a sequence A[1], A[2], ..., A[N].

	A query is defined as follows:

	Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 
	Given M queries, write a program that outputs the results of these queries.
*/

// C++ Program to Implement Maximum Sub-Array Sum in a range
#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f

/* Node of the segment tree consisting of:
1. Maximum Prefix Sum,
2. Maximum Suffix Sum,
3. Total Sum,
4. Maximum Sub-Array Sum */
struct Node {
	int maxPrefixSum;
	int maxSuffixSum;
	int totalSum;
	int maxSubarraySum;

	Node()
	{
		maxPrefixSum = maxSuffixSum = maxSubarraySum = -inf;
		totalSum = -inf;
	}
};

// Returns Parent Node after merging its left and right child
Node merge(Node leftChild, Node rightChild)
{
	Node parentNode;
	parentNode.maxPrefixSum = max(leftChild.maxPrefixSum,
								leftChild.totalSum + 
								rightChild.maxPrefixSum);

	parentNode.maxSuffixSum = max(rightChild.maxSuffixSum,
								rightChild.totalSum +
								leftChild.maxSuffixSum);

	parentNode.totalSum = leftChild.totalSum +
						rightChild.totalSum;

	parentNode.maxSubarraySum = max({leftChild.maxSubarraySum,
									rightChild.maxSubarraySum,
									leftChild.maxSuffixSum + 
									rightChild.maxPrefixSum});

	return parentNode;
}

// Builds the Segment tree recursively
void constructTreeUtil(Node* tree, int arr[], int start,
									int end, int index)
{

	/* Leaf Node */
	if (start == end) {

		// single element is covered under this range
		tree[index].totalSum = arr[start];
		tree[index].maxSuffixSum = arr[start];
		tree[index].maxPrefixSum = arr[start];
		tree[index].maxSubarraySum = arr[start];
		return;
	}

	// Recursively Build left and right children
	int mid = (start + end) / 2;
	constructTreeUtil(tree, arr, start, mid, 2 * index);
	constructTreeUtil(tree, arr, mid + 1, end, 2 * index + 1);

	// Merge left and right child into the Parent Node
	tree[index] = merge(tree[2 * index], tree[2 * index + 1]);
}

/* Function to construct segment tree from given array. 
This function allocates memory for segment tree and 
calls constructTreeUtil() to fill the allocated 
memory */
Node* constructTree(int arr[], int n)
{
	// Allocate memory for segment tree
	int x = (int)(ceil(log2(n))); // Height of the tree

	// Maximum size of segment tree 
	int max_size = 2 * (int)pow(2, x) - 1; 
	Node* tree = new Node[max_size];

	// Fill the allocated memory tree
	constructTreeUtil(tree, arr, 0, n - 1, 1);

	// Return the constructed segment tree
	return tree;
}

/* A Recursive function to get the desired 
Maximum Sum Sub-Array,
The following are parameters of the function-

tree	 --> Pointer to segment tree 
index --> Index of the segment tree Node 
ss & se --> Starting and ending indexes of the 
			segment represented by
				current Node, i.e., tree[index]
qs & qe --> Starting and ending indexes of query range */
Node queryUtil(Node* tree, int ss, int se, int qs,
							int qe, int index)
{
	// No overlap
	if (ss > qe || se < qs) {

		// returns a Node for out of bounds condition
		Node nullNode;
		return nullNode;
	}

	// Complete overlap
	if (ss >= qs && se <= qe) {
		return tree[index];
	}

	// Partial Overlap Merge results of Left 
	// and Right subtrees
	int mid = (ss + se) / 2;
	Node left = queryUtil(tree, ss, mid, qs, qe, 
									2 * index);
	Node right = queryUtil(tree, mid + 1, se, qs, 
							qe, 2 * index + 1);

	// merge left and right subtree query results
	Node res = merge(left, right);
	return res;
}

/* Returns the Maximum Subarray Sum between start and end
It mainly uses queryUtil(). */
int query(Node* tree, int start, int end, int n)
{
	Node res = queryUtil(tree, 0, n - 1, start, end, 1);
	return res.maxSubarraySum;
}

int main()
{
	int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    Node* Tree = constructTree(arr, n);
    int q, x, y;
    cin >> q;
    for (int i = 0; i < q; i++){
        cin >> x >> y;
        cout << query(Tree, x-1, y-1, n) << endl;
    }
    return 0;
}


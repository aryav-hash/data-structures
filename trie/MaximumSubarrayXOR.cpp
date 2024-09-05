/*
	VVIMP PROBLEM ON TRIES:
	Given an array of N integers, find the subarray whose XOR is maximum.
	Sample Input 1:
	4
	1 2 3 4
	Sample Output 1:
	7
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[2];
    int val;

    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }

    void setVal(int v){
        val = v;
    }

    int getVal(){
        return val;
    }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i)&1;
            if (!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
        node->setVal(num);
    }

    int query(int px, Node* node){
        
        for (int i = 31; i >= 0; i--){
            int bit = (px >> i)&1;
            if (node->containsKey(1 - bit)){
                node = node->get(1 - bit);
            }else{
                node = node->get(bit);
            }
        }
        int val = node->getVal();
        return (px^val);
    }

    int calSubarrXor(vector<int>&arr, int n){
        Node* node = root;
        int px = 0;
        insert(px);
        int ans = INT_MIN;

        for (int i = 0; i < n; i++){
            px = px^arr[i];
            insert(px);

            ans = max(ans, query(px, node));
        }

        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Trie t;
    vector<int>arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int res = t.calSubarrXor(arr, n);

    cout << res << endl;
    return 0;
}

// https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/ 

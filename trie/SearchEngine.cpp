/*
	SEARCH ENGINE PROBLEM :--
	Let us see how search engines work. Consider the following simple auto complete feature. 
	When you type some characters in the text bar, the engine automatically gives best matching options among it's database. 
	Your job is simple. Given an incomplete search text, output the best search result.

	Each entry in engine's database has a priority factor attached to it. 
	We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. 
	For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. 
	In case no such string exists, print -1.
	
	Example:
	Input:	2 1
		potential 10
		potent 8
		pot
	Output:	10
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int val;

    Node() {
        // Initialize the links array and the value
        val = -1;  // Use -1 to indicate no valid word yet
        for (int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word, int val) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            // Update max value at each node for optimal search.
            node->val = max(node->val, val);
        }
    }

    int searchWord(string s) {
        Node* node = root;
        for (int i = 0; i < s.length(); i++) {
            if (!node->containsKey(s[i])) {
                return -1;  // If prefix doesn't exist
            }
            node = node->get(s[i]);
        }
        return node->val;  // Return the max value for the prefix
    }
};

vector<int> searchEngine(vector<pair<string, int>> database, vector<string> text) {
    Trie t;
    for (auto &it : database) {
        t.insert(it.first, it.second);
    }

    vector<int> arr;
    for (auto &it : text) {
        int ans = t.searchWord(it);
        arr.push_back(ans);
    }

    return arr;
}

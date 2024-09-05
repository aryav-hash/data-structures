/*
	You are given a binary matrix 'MATRIX' of 'N' rows and 'M' columns.

	Your task is to return all the unique rows in the order they appear in the matrix.

	For example:

	Matrix = [ [1,0,1], [0,0,1 ], [1,0,1 ]] 	
	Result = [ [1,0,1], [0,0,1] ]. 
	The row [1,0,1] is before [0,0,1] as it appears before in matrix.
	Note: In the binary matrix, all the entries are either 0 or 1.
*/

#include<bits/stdc++.h>

class TrieNode{
      public:
      TrieNode* links[2];
      TrieNode(){
            for (int i = 0; i < 2; i++){
                  links[i] = nullptr;
            }
      }
};

class Trie{
      public:
      TrieNode* root;
      Trie(){
            root = new TrieNode();
      }

      bool insert(string word){
            TrieNode* node = root;
            bool flag = false; // Assuming it does not exist.
            for (int i = 0; i < word.length(); i++){
                  int digit = word[i] - '0';
                  if (node->links[digit] == nullptr){
                        node->links[digit] = new TrieNode();
                        flag = true; // Confirmation.
                  }
                  node = node->links[digit];
            }
            return flag;
      }
};

vector<vector<int>> uniqueRow(vector<vector<int>> &matrix, int n, int m)
{
      // Write Your code here.
      vector<vector<int>>ans;
      Trie t;
      for (int i = 0; i < n; i++){
            vector<int>a;
            string s = "";
            for (int j = 0; j < m; j++){
                  s += to_string(matrix[i][j]);
                  a.push_back(matrix[i][j]);
            }
            if(t.insert(s)){
                  ans.push_back(a);
            }
      }
      return ans;
}

/*
	Another approach is:
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> uniqueRow(vector<vector<int>> &matrix, int n, int m)
{
	vector<vector<int>>ans;
	set<vector<int>>st;
	for (int i = 0; i < n; i++){
		vector<int>a;
		string s = "";
		for (int j = 0; j < m; j++){
			a.push_back(matrix[i][j]);
			s += to_string(matrix[i][j]);
		}
		if (st.find(a) != st.end()){
			st.insert(a);
			ans.push_back(a);
		}
	}
	return ans;
}
*/

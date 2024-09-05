/*
	<<<VIMP PROBLEM>>>
	This is a graph/string manipulation problem relying on the bfs algo.
	
	You are given two strings BEGIN and END and an array of strings DICT. 
	Your task is to find the length of the shortest transformationsequence from BEGIN to END such 
	that in every transformation you can change exactly one alphabet and the word formed after each 
	transformation must exist in DICT.

	Note:

	1. If there is no possible path to change BEGIN to END then just return -1.
	2. All the words have the same length and contain only lowercase english alphabets.
	3. The beginning word i.e. BEGIN will always be different from the end word i.e. END (BEGIN != END).
*/

#include<bits/stdc++.h>
int wordLadder(string begin, string end, vector<string> &dict) 
{
	// Write your code here.
	queue<pair<string , int>> q;
	q.push({begin, 1});
	unordered_set<string> st(dict.begin(), dict.end());

	while (!q.empty()){
		string word = q.front().first;
		int len = q.front().second;
		q.pop();
		
		if (word == end) return len;

		for (int i = 0; i < word.length(); i++){
			char original = word[i];
			for (char ch = 'a'; ch <= 'z'; ch++){
				word[i] = ch;
				if (st.find(word) != st.end()){
					st.erase(word);
					q.push({word, len+1});
				}
			}
			word[i] = original;
		}
	}

	return -1;
}
/*
Test case:
der dfs
5
des der dfr dgt dfs
Output:
3

https://www.youtube.com/watch?v=tRPda0rcf8E&t=16s 
*/

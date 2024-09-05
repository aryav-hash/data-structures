/* 
	VVIMP QUESTION
	Given a string s, partition s such that every substring of the partition is a palindrome. 
	Return all possible palindrome partitioning of s.
	
	EXAMPLE :- 
	Input : s = "aab"
	Output : [["a", "a", "b"], ["aa", "b"]]
*/


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool isPalindrome(string &s, int start, int end){
        while (start <= end){
            if (s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    
    void func(int index, vector<string>path, vector<vector<string>>&ans, string&s){
        
        if (index == s.length()){
            ans.push_back(path);
            return ;
        }
        
        for (int i = index; i < s.length(); i++){
            if (isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                func(i+1, path, ans, s);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> palindromicPartition(string &s){
        vector<string> path;
        vector<vector<string>> ans;
        func(0, path, ans, s);
        return ans;
    }
};

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        Solution obj;
        vector<vector<string>> Strings = obj.palindromicPartition(s);
        
        for (auto path : Strings){
            for (auto cell : path){
                cout << cell << " ";
            }cout<< endl;
        }cout << endl;
    }
    return 0;
}


/*
	INPUT : 2 aabb abccba
	OUTPUt:
		a a b b 
		a a bb 
		aa b b 
		aa bb 

		a b c c b a 
		a b cc b a 
		a bccb a 
		abccba 
*/


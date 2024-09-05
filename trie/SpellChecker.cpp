/*
	VVIMP PROBLEM: You are given a list of strings, ‘DICTIONARY[]’ that represents the correct spelling of words and a query string ‘QUERY’ that may have incorrect spelling. You have to check whether the spelling of the string ‘QUERY’ is correct or not. If not, then return the list of suggestions from the list ‘DICTIONARY’. Otherwise, return an empty list which will be internally interpreted as the correct string.

Note:

1) The suggested correct strings for the string  ‘QUERY’ will be all those strings present in the ‘DICTIONARY[]’ that have the prefix same as the longest prefix of string ‘QUERY’.

2) The ‘DICTIONARY[]’ contains only distinct strings.
For example:

Given 'DICTIONARY[]' = {“ninja”, “ninjas”, “nineteen”, “ninny”} and query = “ninjk”. Since “ninjk” is not present in the ‘DICTIONARY[]’, it is an incorrect string. The suggested current spellings for “ninjk” are “ninja” and “ninjas”. It is because “ninj” is the longest prefix of “ninjk” which is present as the prefix in ‘DICTIONARY’.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int went;
    int end;
    Node(){
        went = 0;
        end = 0;
        for (int i = 0; i < 26; i++) links[i] = nullptr;
    }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(const string word){
        Node* node = root;
        for (char ch : word){
            int idx = ch - 'a';
            if (node->links[idx] == nullptr){
                node->links[idx] = new Node();
            }
            (node->links[idx])->went++;
            node = node->links[idx];
        }
        node->end++;
    }

    string check(string word){
        Node* node = root;
        string str = "";
        for (char ch : word){
            int idx = ch - 'a';
            if (node->links[idx] == nullptr){
                break;
                return str;
            }else{
                str += ch;
                node = node->links[idx];
            }
        }
        return str;
    }

    void f(vector<string>&ans, string prefix, Node* node){
        if (node->end > 0){
            ans.push_back(prefix);
            return;
        }

        for (int i = 0; i < 26; i++){
            if (node->links[i] != nullptr){
                string temp = prefix + char('a' + i);
                f(ans, temp, node->links[i]);
            }
        }
    }

    void suggest(vector<string>&ans, string prefix){
        Node* node = root;
        f(ans, prefix, node);
    }
};

vector<string> spellChecker(vector<string> &dictionary, string &query){
    // Write your code here.
    Trie t;
    for(const string &it : dictionary){
        t.insert(it);
    }

    vector<string> ans;

    string s = t.check(query);
    if (s == query){
        return ans;
    }

    t.suggest(ans, s);

    return ans;
}

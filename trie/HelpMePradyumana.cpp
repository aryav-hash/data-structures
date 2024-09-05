/*
	IMPORTANT QUESTION>>
	Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct
	more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will 
	restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct 
	changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. 
	As Pradyumn is busy with his front - end work of his App. He asks you to help him. 
	He said "You will be given set of words(words may repeat too but counted as one only). 
	Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words 
	of dictionary which have the prefix same as given by user as input. And if no such words are available, 
	add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P 
	So, implement a program for him such that he can release it on Fun Store.
	
	Sample Input 1:
	3
	fact
	factorial
	factory
	2
	fact
	pradyumn
	Sample Output 1:
	fact
	factorial
	factory
	No suggestions
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    string s;

    Node(){
        for (int i = 0; i < 26; i++){
            links[i] = NULL;
        }
        s = "";
    }

    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for (int i = 0; i < word.length(); i++){
            if (!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->s = word;
    }

    vector<string> getStrings(string word){
        Node* node = root;
        vector<string> ans;
        for (int i = 0; i < word.length(); i++){
            if (!node->containsKey(word[i])){
                insert(word);
                return ans;
            }
            node = node->get(word[i]);
        }

        if (!(node->s).empty()) ans.push_back(word);

        queue<Node*> q;
        for (int i = 0; i < 26; i++){
            if (node->links[i] != NULL){
                Node* newnode = node->links[i];
                q.push(newnode);
            }
        }

        while (!q.empty()){
            Node* temp = q.front();
            q.pop();

            if (!(temp->s).empty()) ans.push_back(temp->s);

            for (int i = 0; i < 26; i++){
                if (temp->links[i] != NULL){
                    Node* newnode = temp->links[i];
                    q.push(newnode);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main(){
    int n;
    cin >> n;
    Trie t;
    string word;
    for (int i = 0; i < n; i++){
        cin >> word;
        t.insert(word);
    }
    int q;
    cin >> q;
    string str;
    for (int i = 0; i < q; i++){
        cin >> str;
        vector<string> v = t.getStrings(str);
        if (v.empty()) cout << "No suggestions" << endl;
        for (auto &it : v){
            cout << it << endl;
        }
    }
    return 0;
}



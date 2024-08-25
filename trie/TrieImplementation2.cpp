#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    
    bool containsKey(char ch){
        return (links[ch - 'a'] != NULL);
    }
    
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch - 'a'];
    }
    
    void increasePrefix(){
        cntPrefix++;
    }
    
    void increaseEndWith(){
        cntEndWith++;
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
            node->increasePrefix();
        }
        node->increaseEndWith();
    }
    
    int countEndsWith(string word){
        Node* node = root;
        for (int i = 0; i < word.length(); i++){
            if (node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->cntEndWith;
    }
    
    int countStartsWith(string word){
        Node* node = root;
        for (int i = 0; i < word.length(); i++){
            if (node->containsKey(word[i])){
                node = node->get(word[i]);
            }else{
                return 0;
            }
        }
        return node->cntPrefix;
    }
};

int main(){
    Trie t;
    t.insert("aryav");
    t.insert("aryav");
    t.insert("aryan");
    cout << t.countEndsWith("aryav") << endl;
    cout << t.countStartsWith("ar") << endl;
    cout << t.countEndsWith("aryan") << endl;
    return 0;
}

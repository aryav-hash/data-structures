/*
	Similar to the Maximum Subarray Problem but much easier !!
	You are given two arrays of non-negative integers say ‘arr1’ and ‘arr2’. 
	Your task is to find the maximum value of ( ‘A’ xor ‘B’ ) where ‘A’ and ‘B’ are any elements from 
	‘arr1’ and ‘arr2’ respectively and ‘xor’ represents the bitwise xor operation.
	
	Example:
	Input:  1
		7 7
		6 6 0 6 8 5 6
		1 7 1 7 8 0 2
	
	Output:
		15
*/

struct Node{
    Node* links[2];
    
    bool containsKey(int bit){
        return (links[bit] != NULL);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{
    private:
    Node* root;

    public:
    Trie(){
        root = new Node();
    }

    void insertion(int num){
        Node* node = root;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i)&1;
            if (!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int mNum = 0;
        for (int i = 31; i >= 0; i--){
            int bit = (num >> i)&1;
            if (node->containsKey(1 - bit)){
                mNum = mNum | (1 << i);
                node = node->get(1 - bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return mNum;
    }
};

int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.
    Trie trie; 
    for(auto &it : arr1){
        trie.insertion(it);
    }

    int res = 0;
    for (auto &it : arr2){
        res = max(res, trie.getMax(it));
    }  

    return res;
}

// https://www.naukri.com/code360/problems/maximum-xor_973113?leftPanelTabValue=PROBLEM

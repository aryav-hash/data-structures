#include<bits/stdc++.h>
using namespace std;
class kmpAlgo{
    public:
    vector<int> longestPrefixSuffix(string &b, int m){
        vector<int> ans(m, 0);
        int pre = 0, suf = 1;
        
        while (suf < m){
            if (b[pre] == b[suf]){
                ans[suf] = pre+1;
                pre++;
                suf++;
            }
            else{
                if (pre == 0){
                    suf++;
                }
                else{
                    pre = ans[pre-1];
                }
            }
        }
        return ans;
    }
    bool isSubStr(string &a, string &b){
        int n = a.length();
        int m = b.length();
        vector<int> lps = longestPrefixSuffix(b, m);
        
        int first = 0, second = 0;
        // first is for iterating through string a.
        // second is for iterating through string b.
        while (first < n && second < m){
            // match
            if (a[first] == b[second]){
                first++, second++;
            }
            // mismatch
            else{
                // second == 0
                if (second == 0){
                    first++;
                }
                // second != 0
                else{
                    second = lps[second-1];
                }
            }
        }
        if (second == m){
            return true;
        }
        return false;
    }
};
int main(){
    int t;
    cin >> t;
    while (t--){
        string a, b;
        cin >> a >> b;
        kmpAlgo obj;
        if (obj.isSubStr(a, b)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}

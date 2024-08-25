#include<bits/stdc++.h>
using namespace std;
class LongestPrefixSum{
    public:
    int sol(string &s){
        vector<int>lps(s.size(), 0);
        int pre = 0, suf = 1;
        
        while (suf < s.size()){
            // Match
            if (s[pre] == s[suf]){
                lps[suf] = pre+1;
                suf++, pre++;
            }
            // Not Match
            else{
                if (pre == 0){
                    suf++;
                }else{
                    pre = lps[pre-1];
                }
            }
        }
        return lps[s.size()-1];
    }   
};
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        LongestPrefixSum obj;
        cout << obj.sol(s) << endl;
    }
    return 0;
}

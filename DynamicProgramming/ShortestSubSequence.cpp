/*
	Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
	Note: input data will be such so there will always be a solution.
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>dp(1001, vector<int>(1001, -1));

int rec(int n, int m, string &s, string &t){
    if (n==0){
        return INT_MAX-5;
    }
    if (m==0){
        return 1;
    }
    if (dp[n][m] != -1){
        return dp[n][m];
    }
    int ans = INT_MAX-5;
    int c = s[n-1];
    int j;
    for (j = m-1; j >= 0; j--){
        if (t[j] == c) break;
    }
    if (j == -1){
        ans = 1;
    }
    else{
        ans = min(rec(n-1, m, s, t), 1+rec(n-1, j, s, t));
    }
    dp[n][m] = ans;
    return ans;
}

int main(){
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();
    cout << rec(n, m, a, b) << endl;
    return 0;
}

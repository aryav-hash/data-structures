/*
	Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. 
	Edit Distance of two strings is minimum number of steps required to make one string equal to other. 
	In order to do so you can perform following three operations only :

	1. Delete a character

	2. Replace a character with another one

	3. Insert a character
	Note - Strings don't contain spaces
	
	Sample Input 1 :
	1
	abc
	dc
	Sample Output 1 :
	2
*/

#include<bits/stdc++.h>
using namespace std;

int f(int ind1, int ind2, string &a, string &b, vector<vector<int>>&dp){
    if (ind1 < 0) return ind2+1;

    if (ind2 < 0) return ind1+1;

    if (dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if (a[ind1] == b[ind2]) return dp[ind1][ind2] = f(ind1-1, ind2-1, a, b, dp);

    return dp[ind1][ind2] = 1 + min({f(ind1-1, ind2, a, b, dp), f(ind1, ind2-1, a, b, dp), f(ind1-1, ind2-1, a, b, dp)});
}

int main(){
    int t;
    cin >> t;
    while (t--){
        string a, b;
        cin >> a >> b;
        int n = a.length(), m = b.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        cout << f(n-1, m-1, a, b, dp) << endl;
    }
    // write your code here
    return 0;
}



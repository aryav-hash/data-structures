/*
	Given a string, count the number of distinct subsequences of it ( including empty subsequence ). 
	For the uninformed, A subsequence of a string is a new string which is formed from the original 
	string by deleting some of the characters without disturbing the relative positions of the remaining characters.
	For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
	
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const long long int M = 1e9+7;

ll distinctSubSequences(ll n, string &s){
	unordered_map <char, ll> ump;
	vector<ll>dp(n+1);
	dp[0] = 1; // Blank Space.
	for (ll i = 1; i <= n; i++){
		dp[i] = (2*(dp[i-1]%M))%M;
		char ch = s[i-1];
		if (ump.find(ch) != ump.end()){
			// Repeats.
			ll index = ump[ch];
			dp[i] = dp[i] - dp[index-1];
		}
		// Put that character in the unordered_map.
		ump[ch] = i;
	}
	return (dp[n]%M + M)%M;
}

int main(){
	int ts;
	cin >> ts;
	while (ts--){
		string s;
		cin >> s;
		ll n = s.length();
		cout << distinctSubSequences(n, s) << endl;
	}
	return 0;	
}

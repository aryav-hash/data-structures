/*
	You just received another bill which you cannot pay because you lack the money.
	Unfortunately, this is not the first time to happen, and now you decide to investigate the cause of your constant monetary shortness. 
	The reason is quite obvious: the lion's share of your money routinely disappears at the entrance of party localities.
	You make up your mind to solve the problem where it arises, namely at the parties themselves. 
	You introduce a limit for your party budget and try to have the most possible fun with regard to this limit.
	You inquire beforehand about the entrance fee to each party and estimate how much fun you might have there. 
	The list is readily compiled, but how do you actually pick the parties that give you the most fun and do not exceed your budget?
	Write a program which finds this optimal set of parties that offer the most fun. 
	Keep in mind that your budget need not necessarily be reached exactly. Achieve the highest possible fun level, 
	and do not spend more money than is absolutely necessary.
	
	Sample Input:
	5
	1 7 9 7 2 
	5 5 2 4 7 
	12
	Sample Output:
	10 17
*/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> f(int ind, int w, vector<int>& weights, vector<int>& values, vector<vector<pair<int, int>>>& dp) {
    if (ind < 0) return {0, 0};  // No parties left to attend

    if (dp[ind][w].first != -1) return dp[ind][w];  // Return memoized result

    // Option 1: Don't take the current party
    pair<int, int> b = f(ind - 1, w, weights, values, dp);

    // Option 2: Take the current party (only if weight allows)
    pair<int, int> a = {0, 0};
    if (w >= weights[ind]) {
        pair<int, int> taken = f(ind - 1, w - weights[ind], weights, values, dp);
        a = {taken.first + values[ind], taken.second + weights[ind]};
    }

    // Compare the two options:
    if (a.first > b.first) {
        dp[ind][w] = a;  // More fun by taking the current party
    } else if (a.first == b.first) {
        dp[ind][w] = (a.second < b.second) ? a : b;  // Same fun, choose the one with less cost
    } else {
        dp[ind][w] = b;  // More fun by not taking the current party
    }

    return dp[ind][w];
}

pair<int, int> maxWeight(int n, vector<int>& weights, vector<int>& values, int mw) {
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(mw + 1, {-1, 0}));
    return f(n - 1, mw, weights, values, dp);
}

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    vector<int> values(n);
    
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    int w;
    cin >> w;

    pair<int, int> result = maxWeight(n, weights, values, w);
    cout << result.second << " " << result.first << endl;  // Output total cost and total fun
    
    return 0;
}

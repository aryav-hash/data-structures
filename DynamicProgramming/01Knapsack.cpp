/*
	A thief robbing a store and can carry a maximal weight of W into his knapsack. 
	There are N items and ith item weigh wi and is of value vi. 
	What is the maximum value V, that thief can take ?
	Note: Space complexity should be O(W).
	
	Sample Input 1 :
	4
	1 2 4 5
	5 4 8 6
	5	
	Sample Output :
	13
*/

#include<bits/stdc++.h>
using namespace std;

int f(int ind, int w, vector<int>&weights, vector<int>&values, vector<vector<int>>&dp){
    
    if (ind < 0) return 0;
    
    if (dp[ind][w] != -1) return dp[ind][w];

    int a = 0, b = 0;
    // take.
    if (w >= weights[ind]){
        a = values[ind] + f(ind-1, w - weights[ind], weights, values, dp);
    }

    b = f(ind-1, w, weights, values, dp);

    return dp[ind][w] = max(a, b);
}

int maxWeight(int n, vector<int>&weights, vector<int>&values, int mw){
    vector<vector<int>>dp(n, vector<int>(mw+1, -1));
    return f(n-1, mw, weights, values, dp);
}

int main(){
    int n;
    cin >> n;
    vector<int>weights(n);
    vector<int>values(n);
    for (int i = 0; i < n; i++){
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++){
        cin >> values[i];
    }
    int w;
    cin >> w;
    cout << maxWeight(n, weights, values, w) << endl;
    return 0;
}

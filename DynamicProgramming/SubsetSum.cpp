/*
	Given an array of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.
	Sample Input
	1
	3
	1 2 3
	4
	Sample Output
	Yes
*/

#include<bits/stdc++.h>
using namespace std;

int f(int index, int target, vector<int>&arr, vector<vector<int>>&dp){
    if (target == 0) return 1;
    
    if (index < 0) return 0;

    if (dp[index][target] != -1) return dp[index][target];
    // pick
    int a = 0, b = 0;
    if (target >= arr[index]){
        a = f(index-1, target - arr[index], arr, dp);
    }
    b = f(index-1, target, arr, dp);

    return dp[index][target] = a | b;
    // do not pick
}

int main(){
    int ts;
    cin >> ts;
    while (ts--){
        int n;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        int t;
        cin >> t;
        vector<vector<int>>dp(n+1, vector<int>(t+1, -1));
        if (f(n-1, t, arr, dp)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    // write your code here
    return 0;
}

/*
	You are given a string 'str' of length 'n'.
	Find the minimum number of partitions in the string so that no partition is empty and every partitioned substring is a palindrome.
	
	Example: Input: 'str' = "aaccb"
		 Output: 2
		 Explanation: We can make a valid partition like aa | cc | b. 
*/

#include<bits/stdc++.h>

bool isPalindrome(int start, int end, string s){
    while (start < end){
        if (s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

int func(int index, string str, int n, vector<int>&dp){
    if (index == n){
        return 0;
    }

    if (dp[index] != -1){
        return dp[index];
    }

    int res = INT_MAX;
    for (int j = index; j < n; j++){
        if (isPalindrome(index, j, str)){
            int val = 1 + func(j+1, str, n, dp);
            res = min(res, val);
        }
    }
    
    return dp[index] = res;
}

int palindromePartitioning(string str)
{
    int n = str.length();
    vector<int> dp(n+1, -1);
    int res = func(0, str, n, dp);
    return res-1; // Since there is a partition at the end.
}

// The solution is based upon the FRONT PARTITION concept.

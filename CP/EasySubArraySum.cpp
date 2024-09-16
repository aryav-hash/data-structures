// Easy Subarray Sum.

#include <bits/stdc++.h>
using namespace std;

int f(vector<int>&arr, int n){
    
    int fir = 0, last = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] > 0){
            fir = i;
            break;
        }
    }
    
    for (int i = n-1; i >= 0; i--){
        if (arr[i] > 0){
            last = i;
            break;
        }
    }
    
    if (fir == last) return 0;
    
    int res = 0;
    for (int i = fir; i < last; i++){
        if (arr[i] < 0) res++;
    }
    
    return res;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--){
	    int n;
	    cin >> n;
	    vector<int> arr(n);
	    for (int i = 0; i < n; i++){
	        cin >> arr[i];
	    }
	    
	    cout << f(arr, n) << endl;
	}
    return 0;
}

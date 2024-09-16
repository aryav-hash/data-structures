#include <bits/stdc++.h>
using namespace std;

int f(vector<int>&arr, int n){
    int sum = 0;
    int neg = 0;
    
    for (int i = 0; i < n; i++){
        if (arr[i] < 0){
            arr[i] = abs(arr[i]);
            neg = neg+1;
        } 
    }
    
    sort(arr.begin(), arr.end());
    
    if (neg%2 == 1){
        arr[0] *= -1;
    }
    
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    
    return sum;
}

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
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


/* Problem statement:-
You are given an integer ’N’ denoting the length of the array ‘Arr’ of strings made up of lower case English alphabets. The cost of this array is equal to the sum of length of each string in the array.

You can select a new string ‘S’ of length ‘N’, you are now allowed to delete the prefix from the strings in the array (This leads to lowering the cost of the array), the deleted prefix should be exactly the same as the selected string ‘S.

Find the string ‘S’ such that the cost of the array ‘Arr’ is minimized. If multiple strings exist, then find the lexicographically smallest string amongst them.

For Example :
If the array of strings is: {co, code, studio, codingninjas, coding, debug, coder, cipher} 
Then the original cost of the array is 2 + 4 + 6 + 12 + 6 + 5 + 5 + 6 = 46.

If we select the new string as “cod” and delete the matching prefixes if exists then the array becomes: {co, e, studio, ingninjas, ing, debug, er, cipher}, and the cost now becomes: 2 + 1 + 6 + 9 + 3 + 5 + 2 + 6 = 34.

You can check for any other possible string, the cost will not become less than 34, hence the optimal answer for this case is “cod”. */



string matchingPrefix(int n, vector < string > arr) {
   // Write your code here
   int cost = 0;
   unordered_map<string, int>mp;

   for (int i = 0; i < n; i++){
      cost += arr[i].size();
      string pre = "";
      for (auto it : arr[i]){
         pre += it;
         mp[pre]++;
      }
   }

   int mCost = INT_MAX;
   string s;
   for (auto u : mp){
      int pLen = (u.first).size();
      int freq = u.second;
      int curCost = cost - pLen*freq;
      if (curCost < mCost){
         mCost = curCost;
         s = u.first;
      }
      if (curCost == mCost){
         if (u.first < s){
            s = u.first;
         }
      }
   }

   return s;
}

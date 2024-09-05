/* VVIMP Question on strings.

You are given a string ‘Str’ of length ‘N’. Find the last substring of ‘Str’ in lexicographical order.

In Lexicographical order string ‘S1’ comes before string ‘S2’ if S1 is the prefix of S2 and (|S1| < |S2|), or if none of them is a prefix of the other and at the first position where they differ, the character in ‘S1’ is smaller than the character in ‘S2’.

Consider string ‘Str’ = “abba”, then its substring in lexicographical order is [“a”, “ab”, “abb”, “abba”, “b”, “bb”, “bba”].  Clearly, the last substring in lexicographical order is  “bba”. */


string findLastSubstring(string &s) {
    // Write your code here.
    int n = s.size();
    int strIndex = 0;

    for (int nIndex = 1, offset = 0; nIndex + offset < n; ){
        if (s[nIndex + offset] == s[strIndex + offset]){
            ++offset;
        }

        else if (s[nIndex + offset] > s[strIndex + offset]){
            strIndex = strIndex + offset + 1;
            offset = 0;
            if (nIndex <= strIndex){
                nIndex = strIndex+1;
            }
        }

        else{
            nIndex += offset + 1;
            offset = 0;
        }
    }

    return s.substr(strIndex);
}

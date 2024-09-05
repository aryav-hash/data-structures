int longestChunkedPal(string &s)
{
	// Write your code here.
    int res = 0;
    int n = s.length();
    string left = "", right = "";

    for (int i = 0; i < n; i++){
        left += s[i];
        right = s[n - i - 1] + right;

        if (left == right){
            res++;
            left = "";
            right = "";
        }
    }

    return res;
}

/* 	string = abcdefgdefabc 
	logic = (abc)(def)(g)(def)(abc)
	ans = 5	
*/

int minCharsforPalindrome(string str) {
	// Write your code here.
	int n = str.length();
	// Two pointers:-
	int a = 0, b = n-1, t = b;
	int num = 0;
	
	while (a < b){
		if (str[a] == str[b]){
			a++;
			b--;
		}
		else{
			num++;
			a = 0;
			b = --t;
		}
	}

	return num;	
}

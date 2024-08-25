#include <bits/stdc++.h>
using namespace std;

const long long PRIME = 31;        // A small prime number for hashing
const long long MOD = 1e9 + 7;     // A large prime number for modulus to avoid collisions

class RabinKarpAlgo {
public:
    bool find(const string& pattern, const string& text) {
        int n = text.length();
        int m = pattern.length();

        if (m > n) return false;  // If the pattern is longer than the text, no match is possible

        long long patternHash = 0, textHash = 0, power = 1;

        // Compute the hash of the pattern and the first window of the text
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * PRIME + (pattern[i] - 'a' + 1)) % MOD;
            textHash = (textHash * PRIME + (text[i] - 'a' + 1)) % MOD;
            if (i < m - 1) {
                power = (power * PRIME) % MOD;  // Precompute the power of PRIME^(m-1)
            }
        }

        // Check if the first window matches the pattern
        if (patternHash == textHash && text.substr(0, m) == pattern) {
            return true;
        }

        // Use rolling hash to compare subsequent windows
        for (int i = m; i < n; i++) {
            // Remove the first character of the previous window and add the new character
            textHash = (textHash - (text[i - m] - 'a' + 1) * power) % MOD;
            textHash = (textHash + MOD) % MOD;  // Ensure non-negative value
            textHash = (textHash * PRIME + (text[i] - 'a' + 1)) % MOD;

            // Check if the current window matches the pattern
            if (patternHash == textHash && text.substr(i - m + 1, m) == pattern) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pattern, text;
        cin >> pattern >> text;
        RabinKarpAlgo obj;
        if (obj.find(pattern, text)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

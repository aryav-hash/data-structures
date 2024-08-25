#include <bits/stdc++.h>
using namespace std;

// Function to compute the LPS array for the given word.
void computeLPS(const string& word, int* lps) {
    int m = word.length();
    lps[0] = 0; // The LPS value for the first character is always 0

    for (int i = 1; i < m; i++) {
        int j = lps[i - 1]; // Previous LPS value
        // Adjust j to find the proper prefix suffix match
        while (j > 0 && word[i] != word[j]) {
            j = lps[j - 1];
        }

        if (word[i] == word[j]) {
            j++; // Extend the match
        }

        lps[i] = j; // Update LPS value
    }
}

// KMP string matching algorithm to count occurrences of the word in a given string
int KMP(const string& s, const string& word, const int* lps) {
    int n = s.length(); // Length of the string s
    int m = word.length(); // Length of the word to be searched
    string extendedWord = word + '#'; // Add a special character to ensure proper prefix-suffix match

    int occurrences = 0; // Initialize the count of occurrences
    for (int i = 0, j = 0; i < n; i++) {
        // Adjust j to match the current character
        while (j > 0 && s[i] != extendedWord[j]) {
            j = lps[j - 1];
        }

        if (s[i] == extendedWord[j]) {
            j++; // Move to the next character in the word
        }

        if (j == m) {
            // If j reaches the length of the word, an occurrence is found
            occurrences++;
            j = lps[j - 1]; // Adjust j for further searching
        }
    }

    return occurrences; // Return the total count of occurrences
}

// Main function to find occurrences of the word in the grid
int wordSearch(const string* grid, int n, int m, const string& word) {
    int* lps = new int[word.length()]; // Array to store LPS values for the word
    computeLPS(word, lps); // Compute LPS values

    int occurrences = 0; // Initialize the count of occurrences

    // Check rows and their reverses
    for (int i = 0; i < n; i++) {
        occurrences += KMP(grid[i], word, lps); // Check the row
        occurrences += KMP(string(grid[i].rbegin(), grid[i].rend()), word, lps); // Check the reversed row
    }

    // Check columns and their reverses
    for (int j = 0; j < m; j++) {
        string str;
        for (int i = 0; i < n; i++) {
            str.push_back(grid[i][j]); // Construct the column string
        }

        occurrences += KMP(str, word, lps); // Check the column
        occurrences += KMP(string(str.rbegin(), str.rend()), word, lps); // Check the reversed column
    }

    // Check upper diagonals and their reverses
    for (int i = 0; i < n; i++) {
        string str;
        for (int j = 0; i + j < n && j < m; j++) {
            str.push_back(grid[i + j][j]); // Construct the diagonal string (upper-right direction)
        }

        occurrences += KMP(str, word, lps); // Check the diagonal
        occurrences += KMP(string(str.rbegin(), str.rend()), word, lps); // Check the reversed diagonal
    }

    for (int j = 1; j < m; j++) {
        string str;
        for (int i = 0; i < n && j + i < m; i++) {
            str.push_back(grid[i][j + i]); // Construct the diagonal string (upper-right direction)
        }

        occurrences += KMP(str, word, lps); // Check the diagonal
        occurrences += KMP(string(str.rbegin(), str.rend()), word, lps); // Check the reversed diagonal
    }

    // Check lower diagonals and their reverses
    for (int i = 0; i < n; i++) {
        string str;
        for (int j = 0; i - j >= 0 && j < m; j++) {
            str.push_back(grid[i - j][j]); // Construct the diagonal string (lower-right direction)
        }

        occurrences += KMP(str, word, lps); // Check the diagonal
        occurrences += KMP(string(str.rbegin(), str.rend()), word, lps); // Check the reversed diagonal
    }

    for (int j = 1; j < m; j++) {
        string str;
        for (int i = n - 1; i >= 0 && j + (n - 1) - i < m; i--) {
            str.push_back(grid[i][j + (n - 1) - i]); // Construct the diagonal string (lower-right direction)
        }

        occurrences += KMP(str, word, lps); // Check the diagonal
        occurrences += KMP(string(str.rbegin(), str.rend()), word, lps); // Check the reversed diagonal
    }

    delete[] lps; // Free the allocated memory for LPS array
    return occurrences; // Return the total count of occurrences
}

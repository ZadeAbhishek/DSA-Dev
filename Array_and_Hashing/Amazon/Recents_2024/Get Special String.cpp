#include <iostream>
#include <string>
using namespace std;

string getSpecialString(string s) {
    int n = s.size();

    // Helper lambda to get the next character that doesn't cause adjacent duplicates
    auto getNextChar = [](char c, char prev, char next) -> char {
        for (char nextChar = c + 1; nextChar <= 'z'; ++nextChar) {
            if (nextChar != prev && nextChar != next) {
                return nextChar;
            }
        }
        return '\0';  // Return '\0' if no valid character is found
    };

    // Start from the rightmost character and find the first character that can be incremented
    for (int i = n - 1; i >= 0; --i) {
        char prevChar = (i > 0) ? s[i - 1] : '\0';
        char nextChar = (i < n - 1) ? s[i + 1] : '\0';

        // Attempt to increment s[i] to the next valid character
        char nextValidChar = getNextChar(s[i], prevChar, nextChar);

        if (nextValidChar != '\0') {
            s[i] = nextValidChar;

            // Reset all characters after i to ensure the smallest valid lexicographical result
            for (int j = i + 1; j < n; ++j) {
                for (char smallest = 'a'; smallest <= 'z'; ++smallest) {
                    // Ensure no adjacent duplicates
                    if (smallest != s[j - 1] && (j + 1 >= n || smallest != s[j + 1])) {
                        s[j] = smallest;
                        break;
                    }
                }
            }

            // Verify there are no adjacent repeating characters after adjustment
            for (int k = 1; k < n; ++k) {
                if (s[k] == s[k - 1]) {
                    return "-1";  // If adjacent duplicates exist, return "-1"
                }
            }

            return s;  // Return the valid special string
        }
    }

    // Return "-1" if no valid lexicographically larger special string exists
    return "-1";
}

// Driver code to test the function
int main() {
    string s = "abz";
    cout << "Next special string: " << getSpecialString(s) << endl; // Expected output: abca

    return 0;
}
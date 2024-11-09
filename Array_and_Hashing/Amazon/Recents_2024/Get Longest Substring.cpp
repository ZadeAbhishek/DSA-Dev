#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getLongestSubstring(const string& s) {
    int maxLength = 0; // Variable to keep track of the longest valid substring length
    int n = s.size();

    // Iterate over each possible starting character of a substring
    for (int i = 0; i < n - 1; ++i) {
        // Iterate over possible end characters for the substring starting at i
        for (int j = i + 1; j < n; ++j) {
            // Check if the substring from i to j is valid
            if (s[i] < s[j]) {
                maxLength = max(maxLength, j - i + 1); // Update max length if it's the longest so far
            }
        }
    }

    return maxLength;
}

int main() {
    string s = "ecbdca";
    cout << "Longest Substring Length: " << getLongestSubstring(s) << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getLongestSubstring(const string& s) {
    int n = s.size();
    if (n < 2) return 0; // No valid substring if the length is less than 2

    // Check from the start to find the longest substring with s[i] < s[n-1]
    int maxLength = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] < s[n - 1]) {
            maxLength = max(maxLength, n - i);
            break;  // We found the longest possible substring from this direction
        }
    }

    // Check from the end to find the longest substring with s[0] < s[j]
    for (int j = n - 1; j > 0; --j) {
        if (s[0] < s[j]) {
            maxLength = max(maxLength, j + 1);
            break;  // We found the longest possible substring from this direction
        }
    }

    return maxLength;
}

int main() {
    string s = "ecbdca";
    cout << "Longest Substring Length: " << getLongestSubstring(s) << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string generatePalindrome(string q) {
    vector<int> hash(26, 0); // Only need 26 slots for lowercase letters
    string half_string = "";
    char odd_char = '\0';

    // Count character frequencies
    for (char x : q) {
        hash[x - 'a']++;
    }

    // Build half string and detect odd character
    for (int i = 0; i < 26; i++) {
        if (hash[i] % 2 != 0) {
            if (odd_char != '\0') {
                return ""; // More than one odd character makes palindrome impossible
            }
            odd_char = 'a' + i;
        }
        half_string += string(hash[i] / 2, 'a' + i);
    }

    // Construct the full palindrome
    string palindrome = half_string;
    if (odd_char != '\0') {
        palindrome += odd_char; // Add the odd character in the middle
    }
    palindrome += string(half_string.rbegin(), half_string.rend()); // Mirror the half string

    return palindrome;
}

int main() {
    // Example usage
    string q = "ded";

    string result = generatePalindrome(q);

    if (!result.empty()) {
        cout << "Generated palindrome: " << result << endl;
    } else {
        cout << "Palindrome cannot be formed with the given character counts." << endl;
    }

    return 0;
}

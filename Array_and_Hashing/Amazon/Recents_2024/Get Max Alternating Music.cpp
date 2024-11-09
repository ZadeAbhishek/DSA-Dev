#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int getMaxAlternatingMusic(const string& music, int k) {
    int n = music.size();
    int maxLength = 0;

    // Function to calculate maximum length for a given starting pattern
    auto maxAlternatingLength = [&](char startChar) -> int {
        int left = 0, right = 0, flips = 0;
        int maxLen = 0;

        // Sliding window approach
        while (right < n) {
            // Determine the expected character at `right`
            char expectedChar = (right % 2 == 0) ? startChar : (startChar == '0' ? '1' : '0');

            // If the current character does not match the expected pattern, we would need a flip
            if (music[right] != expectedChar) {
                flips++;
            }

            // While the flips exceed `k`, shrink the window from the left
            while (flips > k) {
                char leftExpectedChar = (left % 2 == 0) ? startChar : (startChar == '0' ? '1' : '0');
                if (music[left] != leftExpectedChar) {
                    flips--;
                }
                left++;
            }

            // Update the maximum length of the alternating substring
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    };

    // Calculate the maximum length starting with '0' and '1'
    maxLength = max(maxAlternatingLength('0'), maxAlternatingLength('1'));

    return maxLength;
}

int main() {
    string music = "1001";
    int k = 1;
    cout << "Longest alternating music length: " << getMaxAlternatingMusic(music, k) << endl; // Output should be 3

    return 0;
}
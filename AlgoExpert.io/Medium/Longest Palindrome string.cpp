using namespace std;


// this code is o(n^3)
bool palindrome(string str, int start, int end) {
    while (start <= end) {
        if (str[start] != str[end]) return false;
        start++;
        end--;
    }
    return true;
}

string longestPalindromicSubstring(string str) {
    int maxLength = 0;
    string maxString = "";
    
    for (int i = 0; i < str.size(); i++) {
        for (int j = i; j < str.size(); j++) {
            if (palindrome(str, i, j) && (j - i + 1) > maxLength) {
                maxLength = j - i + 1;
                maxString = str.substr(i, maxLength);
            }
        }
    }
    
    return maxString;
}


// expand arround center by ChatGPT
// this o(n^2)
using namespace std;

string expandAroundCenter(string str, int left, int right) {
    while (left >= 0 && right < str.size() && str[left] == str[right]) {
        left--;
        right++;
    }
    return str.substr(left + 1, right - left - 1);
}

string longestPalindromicSubstring(string str) {
    if (str.empty()) return "";

    string maxString = "";
    
    for (int i = 0; i < str.size(); i++) {
        // Expand around the center for odd length palindromes
        string oddPalindrome = expandAroundCenter(str, i, i);
        if (oddPalindrome.size() > maxString.size()) {
            maxString = oddPalindrome;
        }
        
        // Expand around the center for even length palindromes
        string evenPalindrome = expandAroundCenter(str, i, i + 1);
        if (evenPalindrome.size() > maxString.size()) {
            maxString = evenPalindrome;
        }
    }
    
    return maxString;
}
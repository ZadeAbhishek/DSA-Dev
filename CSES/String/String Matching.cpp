/*
Given a string and a pattern, your task is to count the number of positions where the pattern occurs in the string.
Input
The first input line has a string of length n, and the second input line has a pattern of length m. Both of them consist of characters a–z.
Output
Print one integer: the number of occurrences.
Constraints

1 \le n,m \le 10^6

Example
Input:
saippuakauppias
pp

Output:
2
*/

#include<bits/stdc++.h>
using namespace std;
#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    string pattern;
    cin >> text;
    cin >> pattern;
    string temp = "";
    auto count = 0;

    for (auto i = 0; i < text.size(); i++) {
        temp += text[i]; // Add the current character to the temp string

        // Check if temp has reached the size of the pattern
        if (temp.size() == pattern.size()) {
            if (temp == pattern) count++; // If temp matches the pattern, increment count

            // Slide the window: remove the first character from temp
            temp = temp.substr(1);
        }
    }

    cout << count << "\n";
    return 0;
}
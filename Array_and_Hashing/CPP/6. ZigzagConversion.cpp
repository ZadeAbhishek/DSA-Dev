#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int index = 0;
        vector<string> rows(numRows);
        bool goingDown = false;

        for (char letter : s) {
            rows[index] += letter;
            
            if (index == 0 || index == numRows - 1)
                goingDown = !goingDown;

            if (goingDown) index++;
            else index--;
        }

        string result = "";
        for (string row : rows) {
            result += row;
        }
        return result;
    }
};

int main() {
    // Your main function logic goes here
    return 0;
}

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"


*/
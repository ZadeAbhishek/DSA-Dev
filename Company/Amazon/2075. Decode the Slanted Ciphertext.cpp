#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution2 {
public:
    string decodeCiphertext(string encodedText, int rows) {
        
        int stringSize = encodedText.size();
        // step 1 is to calcuate the number of col
        int col = ((stringSize + rows - 1) / rows); // this formula helps to round of the no of rows
        // step 2 create Decipher matrix 
        vector<vector<char>> dscipherMatrix(rows,vector<char>(col,' ')); // Complete empty string
        for(int index = 0; index < stringSize ; index++) dscipherMatrix[(int)index/col][(int)index%col] = encodedText[index];
        // step 3 Decode it
        vector<string> strings(col,"");
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < col ; j++){
                if(i > j) continue;
                strings[abs(i - j)] += dscipherMatrix[i][j];
            }
        }

        string diChiper = "";
        for(auto x : strings) diChiper += x;

        // remove spaces fron last
        int j = diChiper.size() - 1;
        while(j > 0 && diChiper[j] == ' '){
            diChiper.pop_back();
            j--;
        }
        return diChiper;

    }
};

class Solution3 {
public:
string decodeCiphertext(string &s, int rows) {
    if (s == "") return ""; // Return empty string if input is empty
    int n = s.size();
    string decodedText = "";
    int col = std::ceil(n / rows); // Calculate the number of columns
    int totalNonSpaceChars = 0;
    
    // Count total non-space characters in the input string
    for (char ch : s) {
        if (ch != ' ') totalNonSpaceChars++;
    }
    
    int currentCount = 0;
    int l = 0;
    
    // Loop until all characters are decoded
    while (true) {
        bool finishDecoding = false;
        
        // Iterate through the string with a step size of col+1
        for (int i = l; i < n; i += col + 1) {
            if (s[i] != ' ') currentCount++; // Increment count if character is not a space
            decodedText += s[i]; // Append character to the decoded text
            if (currentCount == totalNonSpaceChars) { // If all non-space characters are decoded
                finishDecoding = true;
                break;
            }
        }
        
        if (finishDecoding) break; // Exit loop if all characters are decoded
        
        l++; // Move to the next character in the string
    }
    
    return decodedText;
}
};

int main() {
    Solution3 solution;
    string encodedText = "ch   ie   pr";
    int rows = 3;
    string decodedText = solution.decodeCiphertext(encodedText, rows);
    cout << "Decoded text: " << decodedText << endl;
    return 0;
}
